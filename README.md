Tic Tac Toe Game
A simple implementation of the classic Tic Tac Toe game in C programming language. This two-player game allows players to take turns marking the cells of a 3x3 grid until one player wins or the game ends in a draw.

Features
Two players can play the game using symbols X and O.
The game detects and announces the winner when three symbols align in a row, column, or diagonal.
Handles invalid moves like selecting an already occupied cell or choosing invalid positions.
Displays the board dynamically with color-coded symbols:
X in Red
O in Green
Ends the game with a message when there is a winner or the game is a draw.
How to Play
Player 1 chooses a symbol: X or O. Player 2 is automatically assigned the other symbol.
Players take turns entering their moves by providing:
Row number (1-3)
Column number (1-3)
Symbol (should match the player's assigned symbol)
The game continues until one player wins or the game ends in a draw.
The program announces the result at the end.
Getting Started
Prerequisites
A C compiler (e.g., GCC).
Compilation
Save the code in a file named tic_tac_toe.c.
Open a terminal or command prompt and navigate to the directory containing the file.
Compile the program using:
bash
Copy code
gcc -o tic_tac_toe tic_tac_toe.c  

Execution
Run the compiled program:

bash
Copy code
./tic_tac_toe  
Code Overview
Functions
initializeboard()
Initializes the board to an empty state.
printboard()
Prints the current state of the board, with symbols displayed in colors.
move(row, column, sym)
Places a symbol on the board and ensures valid moves.
gameover()
Checks if there is a winner.
draw()
Checks if the game is a draw.
playgame()
Controls the game loop, alternating turns between the two players.
Highlights
Uses ANSI escape codes to add color to the console output.
Recursive logic to handle invalid moves.
A user-friendly interface with prompts and error messages for invalid input.
Future Enhancements
Add a single-player mode with an AI opponent.
Implement a graphical user interface (GUI).
Extend the game to support larger grids (e.g., 4x4 or 5x5).
Author
This Tic Tac Toe game was developed by Sri Vaishnavi on 15/05/2024.

License
This project is open-source and free to use for educational purposes
