import React from 'react';

function NoteSearch({ onSearch, searchKeyword }) {
  return (
    <div className="note-search" data-testid="note-search">
      <input
        type="text"
        placeholder="Cari catatan..."
        value={searchKeyword}
        onChange={(e) => onSearch(e.target.value)}
        data-testid="note-search-input"
      />
      {searchKeyword && (
        <button
          className="note-search__clear"
          type="button"
          onClick={() => onSearch('')}
          aria-label="Hapus pencarian"
        >
          &times;
        </button>
      )}
    </div>
  );
}

export default NoteSearch;
