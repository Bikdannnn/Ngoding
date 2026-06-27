/**
 * ========================================================
 * Expense Tracker App — main.js
 * ========================================================
 */

// Global State
let transactions = [];
let editTransactionId = null;

// DOM Elements
const incomeList = document.getElementById('incomeList');
const expenseList = document.getElementById('expenseList');
const transactionForm = document.getElementById('transactionForm');
const titleInput = document.getElementById('transactionFormTitleInput');
const amountInput = document.getElementById('transactionFormAmountInput');
const dateInput = document.getElementById('transactionFormDateInput');
const typeSelect = document.getElementById('transactionFormTypeSelect');
const submitBtn = document.querySelector('[data-testid="transactionFormSubmitButton"]');

const searchForm = document.getElementById('searchTransactionForm');
const searchInput = document.getElementById('searchTransactionFormTitleInput');

const balanceEl = document.querySelector('.tracker-summary__balance-amount');
const incomeEl = document.querySelector('.tracker-summary__stat-amount--income');
const expenseEl = document.querySelector('.tracker-summary__stat-amount--expense');

/**
 * ========================================================
 * Data & Web Storage Management
 * ========================================================
 */

// Load data from localStorage
function loadTransactions() {
  const stored = localStorage.getItem('transactions');
  if (stored) {
    try {
      transactions = JSON.parse(stored);
    } catch (e) {
      console.error('Gagal memuat data transaksi dari localStorage:', e);
      transactions = [];
    }
  } else {
    transactions = [];
  }
}

// Save data to localStorage
function saveTransactions() {
  localStorage.setItem('transactions', JSON.stringify(transactions));
}

// Dispatch event indicating data change
function notifyUpdate() {
  saveTransactions();
  document.dispatchEvent(new Event('transaction:updated'));
}

/**
 * ========================================================
 * Panel Dashboard Update
 * ========================================================
 */
function updateDashboard() {
  let totalIncome = 0;
  let totalExpense = 0;

  transactions.forEach(t => {
    if (t.type === 'income') {
      totalIncome += t.amount;
    } else if (t.type === 'expense') {
      totalExpense += t.amount;
    }
  });

  const totalBalance = totalIncome - totalExpense;

  // Render values to DOM
  balanceEl.textContent = `Rp ${totalBalance}`;
  incomeEl.textContent = `Rp ${totalIncome}`;
  expenseEl.textContent = `Rp ${totalExpense}`;
}

/**
 * ========================================================
 * DOM Manipulation & Rendering
 * ========================================================
 */
function renderTransactions() {
  // Clear containers
  incomeList.innerHTML = '';
  expenseList.innerHTML = '';

  const filterKeyword = searchInput.value.toLowerCase().trim();

  transactions.forEach(t => {
    // Search keyword matching
    if (filterKeyword && !t.title.toLowerCase().includes(filterKeyword)) {
      return;
    }

    // Root Card: must have data-testid="transactionItem"
    const card = document.createElement('div');
    card.setAttribute('data-testid', 'transactionItem');
    card.className = 'tracker-transaction-item';

    // Title: must have data-testid="transactionItemTitle"
    const title = document.createElement('h3');
    title.setAttribute('data-testid', 'transactionItemTitle');
    title.className = 'tracker-transaction-item__title';
    title.textContent = t.title;
    card.appendChild(title);

    // Amount: must have data-testid="transactionItemAmount"
    // Format: "Nominal: Rp" + amount
    const amount = document.createElement('p');
    amount.setAttribute('data-testid', 'transactionItemAmount');
    amount.className = 'tracker-transaction-item__amount';
    amount.textContent = `Nominal: Rp${t.amount}`;
    card.appendChild(amount);

    // Date: must have data-testid="transactionItemDate"
    // Format: "Tanggal: " + date
    const date = document.createElement('p');
    date.setAttribute('data-testid', 'transactionItemDate');
    date.className = 'tracker-transaction-item__date';
    date.textContent = `Tanggal: ${t.date}`;
    card.appendChild(date);

    // Type: must have data-testid="transactionItemType"
    // Format: "Tipe: Pemasukan" or "Tipe: Pengeluaran"
    const type = document.createElement('p');
    type.setAttribute('data-testid', 'transactionItemType');
    type.className = 'tracker-transaction-item__type';
    type.textContent = `Tipe: ${t.type === 'income' ? 'Pemasukan' : 'Pengeluaran'}`;
    card.appendChild(type);

    // Actions Wrapper: div containing button controls
    const actions = document.createElement('div');
    actions.className = 'tracker-transaction-item__actions';

    // Button Change Type: must have data-testid="transactionItemEditTypeButton"
    const editTypeBtn = document.createElement('button');
    editTypeBtn.setAttribute('data-testid', 'transactionItemEditTypeButton');
    editTypeBtn.className = 'tracker-transaction-item__btn';
    editTypeBtn.textContent = 'Ubah Tipe';
    editTypeBtn.addEventListener('click', () => {
      t.type = t.type === 'income' ? 'expense' : 'income';
      notifyUpdate();
    });
    actions.appendChild(editTypeBtn);

    // Button Edit Content: triggers edit state
    const editBtn = document.createElement('button');
    editBtn.className = 'tracker-transaction-item__btn';
    editBtn.textContent = 'Edit';
    editBtn.addEventListener('click', () => {
      startEditing(t);
    });
    actions.appendChild(editBtn);

    // Button Delete: must have data-testid="transactionItemDeleteButton"
    const deleteBtn = document.createElement('button');
    deleteBtn.setAttribute('data-testid', 'transactionItemDeleteButton');
    deleteBtn.className = 'tracker-transaction-item__btn';
    deleteBtn.textContent = 'Hapus';
    deleteBtn.addEventListener('click', () => {
      deleteTransaction(t.id);
    });
    actions.appendChild(deleteBtn);

    card.appendChild(actions);

    // Append card to corresponding category container
    if (t.type === 'income') {
      incomeList.appendChild(card);
    } else {
      expenseList.appendChild(card);
    }
  });
}

/**
 * ========================================================
 * Transaction CRUD Workflows
 * ========================================================
 */

// Start editing a transaction (fill form inputs)
function startEditing(t) {
  editTransactionId = t.id;
  titleInput.value = t.title;
  amountInput.value = t.amount;
  dateInput.value = t.date;
  typeSelect.value = t.type;
  submitBtn.textContent = 'Perbarui';
  
  // Scroll to form smoothly for better mobile experience
  transactionForm.scrollIntoView({ behavior: 'smooth' });
}

// Cancel or complete editing state
function resetForm() {
  editTransactionId = null;
  transactionForm.reset();
  submitBtn.textContent = 'Simpan';
}

// Delete transaction
function deleteTransaction(id) {
  transactions = transactions.filter(t => t.id !== id);
  if (editTransactionId === id) {
    resetForm();
  }
  notifyUpdate();
}

/**
 * ========================================================
 * Event Listeners & Initialization
 * ========================================================
 */

// Form submit event handler
transactionForm.addEventListener('submit', (e) => {
  e.preventDefault();

  const title = titleInput.value.trim();
  const amountVal = amountInput.value.trim();
  const amount = Number(amountVal);
  const date = dateInput.value;
  const type = typeSelect.value;

  // Validation checks (Alert and prevent save if fails)
  if (!title) {
    alert('Judul transaksi tidak boleh kosong!');
    return;
  }
  if (amountVal === '' || isNaN(amount) || amount < 1) {
    alert('Nominal uang tidak boleh kurang dari 1 rupiah!');
    return;
  }
  if (!date) {
    alert('Tanggal transaksi tidak boleh kosong!');
    return;
  }

  if (editTransactionId !== null) {
    // Update existing transaction
    const index = transactions.findIndex(t => t.id === editTransactionId);
    if (index !== -1) {
      transactions[index] = {
        id: editTransactionId,
        title,
        amount,
        date,
        type
      };
    }
    resetForm();
  } else {
    // Create new transaction
    const newTransaction = {
      id: +new Date(),
      title,
      amount,
      date,
      type
    };
    transactions.push(newTransaction);
    transactionForm.reset();
  }

  notifyUpdate();
});

// Search input listener for real-time filtration
searchInput.addEventListener('input', () => {
  renderTransactions();
});

// Search form submit listener
searchForm.addEventListener('submit', (e) => {
  e.preventDefault();
  renderTransactions();
});

// Listen to Custom Event to refresh views
document.addEventListener('transaction:updated', () => {
  renderTransactions();
  updateDashboard();
});

// Initial boot
loadTransactions();
// Dispatch custom event to trigger initial render & calculations
document.dispatchEvent(new Event('transaction:updated'));