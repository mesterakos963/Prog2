private void validate() {
  int n = Integer.parseInt(numberEnteredEt.getText().toString());
  numberTries++;

  if (n == numberToFind) {
    Toast.makeText(this, "Congratulations ! You found the number " + numberToFind +
         " in " + numberTries + " tries", Toast.LENGTH_SHORT).show();
    newGame();
  } else if (n > numberToFind) {
    msgTv.setText(R.string.too_high);
  } else if (n < numberToFind) {
    msgTv.setText(R.string.too_low);
  }
}