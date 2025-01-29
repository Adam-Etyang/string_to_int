# string_to_int
# string to int
Problem: write a program that converts a string of words into integers 
example:
example:
input: "two million"
output : 2,000,000

input : "three hundred thousand"
output : 300,000

input : "twenty two"
output: 22

input : "one hundred and twenty thousand, three hundred and sixty eight"
output :120,368
# my solution
- create a map that has all the tokens(key words that the sting contains) and map to their corresponding values

- preprocess the string such that it only contains the essential tokens or keywords(e.g million, thousand, hundred) by removing non essential words and characters such as "and" or symbols such as commas. store all the tokens in a vector 

- accumulate the values by itterating over each token in the tokens vector:
 
For numbers < 100 (e.g., "twenty", "five"):
Add their value to current.
Example: current += 20 for "twenty".
For "hundred":
Multiply current by 100 to scale it
Example: "three hundred" → current = 3 * 100 = 300.
For large scales (thousand, million, etc.):
Multiply current by the scale (e.g., 1000 for "thousand").
Add the result to total.
Reset current to 0 to start a new segment.
Example: "one hundred twenty thousand" → current = 120 * 1000 = 120000 → total += 120000.
Final Step:
After processing all tokens, add any remaining current to total.


