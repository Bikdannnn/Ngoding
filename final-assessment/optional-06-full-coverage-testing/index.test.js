import { test } from 'node:test';
import assert from 'node:assert';
import sum from './index.js';

test('pengujian fungsi sum secara menyeluruh', () => {
  // Skenario 1: Parameter berupa angka positif yang valid
  assert.strictEqual(sum(2, 3), 5);
  assert.strictEqual(sum(10, 20), 30);

  // Skenario 2: Parameter bukan berupa angka (menguji return 0)
  assert.strictEqual(sum('2', 3), 0);
  assert.strictEqual(sum(2, '3'), 0);
  assert.strictEqual(sum(null, 5), 0);
  assert.strictEqual(sum(undefined, undefined), 0);

  // Skenario 3: Parameter merupakan angka negatif (menguji return 0)
  assert.strictEqual(sum(-1, 5), 0);
  assert.strictEqual(sum(5, -1), 0);
  assert.strictEqual(sum(-2, -2), 0);
});