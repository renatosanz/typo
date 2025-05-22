# Typo
This C program is a typing game that challenges users to replicate randomly generated sentences. It measures the user's typing speed and accuracy by comparing the input against a randomly generated sentence composed of words from a dictionary file.

## Features
- Random sentence generation from a dictionary file (`data.txt`)
- Real-time typing accuracy evaluation
- Performance metrics (time per word)
- Error highlighting for incorrect words
- Interactive replay option

## Requirements
- C compiler (gcc recommended)
- Linux/Unix system (uses `/dev/random`)
- Dictionary file named `data.txt` in the same directory

## Installation
1. Ensure you have a C compiler installed:
   ```bash
   sudo apt-get install gcc
   ```

2. Clone or download the repository

3. Create a `data.txt` file containing words separated by spaces (one long line)

4. Compile the program:
   ```bash
   gcc program.c -o sentence_game
   ```

## Usage
Run the compiled program:
```bash
./sentence_game
```

The program will:
1. Generate and display a random sentence
2. Prompt you to type the sentence
3. Show any errors in your replication
4. Display your average time per word
5. Ask if you want to try again

## Configuration
You can modify these constants in the code:
- `RAND_POS_MAX`: Maximum position for random word selection (adjust based on your `data.txt` size)
- `NUM_WORDS`: Number of words in the generated sentence
- `WORD_SIZE`: Maximum size of each word

## File Structure
- `program.c`: Main source code file
- `data.txt`: Dictionary file containing words separated by spaces

## Functions Overview

### Core Functions
- `main()`: Manages the game loop and user interaction
- `sntCreator()`: Creates a linked list of random words to form a sentence
- `checkSntce()`: Compares user input with the target sentence and returns errors
- `getRandomWord()`: Retrieves a random word from `data.txt`

### Utility Functions
- `getRandNumber()`: Generates a random number using `/dev/random`
- `printSnt()`: Prints a sentence from a linked list
- `printSntERROR()`: Prints error words from a linked list
- `clearSnt()`: Frees memory allocated for a sentence linked list
- `thisTime()`: Gets current timestamp in milliseconds

## Customization
To modify the game:
1. Change difficulty by adjusting `NUM_WORDS` and `WORD_SIZE`
2. Use a different dictionary by replacing `data.txt`
3. Modify the error reporting in `printSntERROR()`

## Known Issues
- The program assumes the existence of `/dev/random` (Linux/Unix specific)
- Input handling may behave differently on different systems
- The dictionary file must be properly formatted (single line, space-separated words)

## License
This program is provided as-is without any specific license. Feel free to modify and use for educational purposes.

## Contributing
Contributions are welcome. Please fork the repository and submit pull requests for any improvements.
