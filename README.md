# TDD Driven StringCalculator

Build a StringCalculator functionality that can take up to two numbers, separated by commas, and will return their sum. 
for example “” or “1” or “1,2” as inputs.

> DO NOT jump into implementation! Read the example and the starting task below.

- For an empty string it will return 0
- Allow the Add method to handle an unknown amount of numbers
- Allow the Add method to handle new lines between numbers (instead of commas).
  - the following input is ok: “1\n2,3” (will equal 6)
  - the following input is NOT ok: “1,\n” (not need to prove it - just clarifying)
- Support different delimiters : to change a delimiter, the beginning of the string will contain a separate line that looks like this: “//[delimiter]\n[numbers…]” for example “//;\n1;2” should return three where the default delimiter is ‘;’ .
the first line is optional. all existing scenarios should still be supported
- Calling Method with a negative number will throw an exception “negatives not allowed” - and the negative that was passed. if there are multiple negatives, show all of them in the exception message.
- Numbers bigger than 1000 should be ignored, so adding 2 + 1001 = 2
- Delimiters can be of any length with the following format: “//[delimiter]\n” for example: “//[***]\n1***2***3” should return 6

## Tasks

## Test Cases – StringCalculator

| Test Case ID | Name                                     | Precondition        | Input                  | Action   | Expected Output / Exception                 | Comment              |
|--------------|------------------------------------------|---------------------|------------------------|----------|---------------------------------------------|----------------------|
| TC01         | Empty string returns zero                | Calculator instance | `""`                   | Call add | `0`                                         | Basic case           |
| TC02         | Single number returns its value          | Calculator instance | `"1"`                  | Call add | `1`                                         | Single value         |
| TC03         | Two numbers separated by comma           | Calculator instance | `"1,2"`                | Call add | `3`                                         | Two values           |
| TC04         | Unknown amount of numbers                | Calculator instance | `"1,2,3,4"`            | Call add | `10`                                        | Multiple values      |
| TC05         | New lines between numbers                | Calculator instance | `"1\n2,3"`             | Call add | `6`                                         | Mixed delimiters     |
| TC06         | Custom single-character delimiter        | Calculator instance | `"//;\n1;2"`           | Call add | `3`                                         | Custom delimiter     |
| TC07         | Custom multi-character delimiter         | Calculator instance | `"//[***]\n1***2***3"` | Call add | `6`                                         | Multi-length delim   |
| TC08         | Negative numbers throw exception         | Calculator instance | `"1,-2,3"`             | Call add | Exception → `"negatives not allowed: -2"`   | Negative validation  |
| TC09         | Multiple negative numbers throw exception| Calculator instance | `"1,-2,-3"`            | Call add | Exception → `"negatives not allowed: -2, -3"` | Negative validation  |
| TC10         | Numbers greater than 1000 are ignored    | Calculator instance | `"2,1001"`             | Call add | `2`                                         | Ignore >1000         |

Establish quality parameters:

- Ensure  maximum complexity (CCN) per function == 3

- Ensure 100% line and branch coverage at every step

  

Start Test-driven approach

1. Write the smallest possible failing test: give input `"" assert output to be 0 ` .
2. Write the minimum amount of code that'll make it pass.
3. Refactor any assumptions, continue to pass this test. Do not add any code without a corresponding test.
