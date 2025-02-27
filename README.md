# Word to Number Converter

This C++ program converts written numbers (in English words) to their numerical integer representations.

## Overview

The Word to Number Converter is a utility that parses textual representations of numbers (e.g., "one hundred twenty-three") and converts them to their corresponding integer values (e.g., 123). This implementation handles numbers from zero up to trillions and includes support for compound number expressions.

## Features

- Converts English word numbers to integers
- Supports numbers from zero to trillions
- Handles compound numbers (e.g., "twenty-three", "one hundred fifty-four")
- Processes scale words (hundred, thousand, million, billion, trillion)
- Ignores connecting words like "and" and punctuation marks
- Case-insensitive processing
- Comprehensive error handling for invalid inputs

## Requirements

- C++ compiler with C++11 support
- Standard C++ libraries: `iostream`, `string`, `stdexcept`, `map`, `vector`, `sstream`, `cctype`

## Usage

1. Compile the program:
   ```
   g++ -std=c++11 word_to_number.cpp -o word_to_number
   ```

2. Run the executable:
   ```
   ./word_to_number
   ```

3. When prompted, enter a number in words:
   ```
   enter the number in words
   one hundred twenty-three
   ```

4. The program will output the numerical value:
   ```
   result: 123
   ```

## Algorithm Details

The conversion process follows these steps:

1. **Preprocessing**: 
   - Converts all text to lowercase
   - Replaces punctuation (commas, periods, hyphens) with spaces
   - Removes connecting words like "and"

2. **Tokenization**:
   - Splits the input string into individual number words

3. **Evaluation**:
   - Maps each token to its numerical value using a predefined dictionary
   - Handles multipliers (hundred) and scale words (thousand, million, etc.)
   - Accumulates values according to English number formation rules

4. **Error Handling**:
   - Throws an exception if an unknown token is encountered

## Examples

| Input Text                                    | Output      |
|-----------------------------------------------|-------------|
| "forty-two"                                   | 42          |
| "one hundred twenty-three"                    | 123         |
| "one thousand, two hundred thirty-four"       | 1,234       |
| "one million, two hundred thirty-four thousand, five hundred sixty-seven" | 1,234,567 |

## Error Handling

The program throws an `invalid_argument` exception when it encounters an unknown word, providing the specific token that caused the error.

## Limitations

- Only handles English number words
- Does not support decimal numbers or fractions
- Does not process negative numbers (no "minus" or "negative" handling)
- Maximum value is limited by the int data type range (up to ~2.1 billion for 32-bit integers)
  
## Possible Extensions

- Support for decimal numbers and fractions
- Handling of negative numbers
- Internationalization support for other languages
- Extended range support using long long or custom big integer implementations
