import React from 'react';
import NoteItem from './NoteItem';

function NotesList({ notes, onDelete, onArchive, searchKeyword, dataTestId = 'notes-list' }) {
  const hasNotes = notes && notes.length > 0;

  if (!hasNotes) {
    return (
      <div className="notes-list" data-testid={dataTestId}>
        <p
          className="notes-list__empty-message"
          data-testid={`${dataTestId}-empty`}
        >
          Tidak ada catatan
        </p>
      </div>
    );
  }

  const getGroupKey = (createdAt) => {
    const date = new Date(createdAt);
    const months = [
      'januari', 'februari', 'maret', 'april', 'mei', 'juni',
      'juli', 'agustus', 'september', 'oktober', 'november', 'desember'
    ];
    return `${months[date.getMonth()]}-${date.getFullYear()}`;
  };

  const formatGroupHeader = (groupKey) => {
    const [month, year] = groupKey.split('-');
    return `${month.charAt(0).toUpperCase() + month.slice(1)} ${year}`;
  };

  // Sort notes descending by date (newest first)
  const sortedNotes = [...notes].sort((a, b) => new Date(b.createdAt) - new Date(a.createdAt));

  const groupedNotes = sortedNotes.reduce((acc, note) => {
    const key = getGroupKey(note.createdAt);
    if (!acc[key]) {
      acc[key] = [];
    }
    acc[key].push(note);
    return acc;
  }, {});

  return (
    <div className="notes-list notes-list--grouped" data-testid={dataTestId}>
      {Object.entries(groupedNotes).map(([groupKey, groupNotes]) => (
        <section key={groupKey} data-testid={`${groupKey}-group`} className="notes-group">
          <div className="notes-group__header">
            <h3 className="notes-group__title">{formatGroupHeader(groupKey)}</h3>
            <span className="notes-group__count" data-testid={`${groupKey}-group-count`}>
              {groupNotes.length} catatan
            </span>
          </div>
          <div className="notes-group__items">
            {groupNotes.map((note) => (
              <NoteItem
                key={note.id}
                note={note}
                onDelete={onDelete}
                onArchive={onArchive}
                searchKeyword={searchKeyword}
              />
            ))}
          </div>
        </section>
      ))}
    </div>
  );
}

export default NotesList;
