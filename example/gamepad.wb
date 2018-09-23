class MyGame extends Game {
  update(state: GameState): void {
   var gamepad = state.input.getGamepad(0);

   if (gamepad != null) {
    if (gamepad.dPad.keys.down.justPressed) {
      print('Down!!!');
    }
   } 
  }
}

function main() : void {
  runGame(new MyGame());
}
