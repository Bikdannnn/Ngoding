import React from 'react';

class NoteInput extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      title: '',
      body: ''
    };

    this.onTitleChangeEventHandler = this.onTitleChangeEventHandler.bind(this);
    this.onBodyChangeEventHandler = this.onBodyChangeEventHandler.bind(this);
    this.onSubmitEventHandler = this.onSubmitEventHandler.bind(this);
  }

  onTitleChangeEventHandler(event) {
    const value = event.target.value;
    if (value.length <= 50) {
      this.setState({ title: value });
    }
  }

  onBodyChangeEventHandler(event) {
    this.setState({ body: event.target.value });
  }

  onSubmitEventHandler(event) {
    event.preventDefault();

    if (this.state.body.length < 10) {
      return;
    }

    this.props.addNote({
      title: this.state.title,
      body: this.state.body
    });

    this.setState({
      title: '',
      body: ''
    });
  }

  render() {
    const { title, body } = this.state;
    const remainingChars = 50 - title.length;
    const isWarning = remainingChars < 10;
    const counterClassName = `note-input__title__char-limit ${isWarning ? 'note-input__title__char-limit--warn' : ''}`;

    return (
      <div className="note-input" data-testid="note-input">
        <h2>Buat catatan</h2>

        {body.length < 10 && body.length > 0 && (
          <p className="note-input__feedback--error">
            Isi catatan minimal harus 10 karakter
          </p>
        )}

        <form
          onSubmit={this.onSubmitEventHandler}
          data-testid="note-input-form"
        >
          <p
            className={counterClassName}
            data-testid="note-input-title-remaining"
          >
            Sisa karakter: {remainingChars}
          </p>
          <input
            className="note-input__title"
            type="text"
            placeholder="Ini adalah judul ..."
            value={title}
            onChange={this.onTitleChangeEventHandler}
            required
            data-testid="note-input-title-field"
          />
          <textarea
            className="note-input__body"
            placeholder="Tuliskan catatanmu di sini ..."
            value={body}
            onChange={this.onBodyChangeEventHandler}
            required
            data-testid="note-input-body-field"
          />
          <button type="submit" data-testid="note-input-submit-button">
            Buat
          </button>
        </form>
      </div>
    );
  }
}

export default NoteInput;
