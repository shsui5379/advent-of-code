/**
 * First step is to run through the raw input data and populate the data structure
 * The data structure shall, for each line, keep track of the round ID, highest red, highest green, highest blue
 * Second step is to run through the data structure to determine if its highest red/green/blue is equal or lower than the expected value. Log those
 * Finally, sum all the logged IDs
 */

import * as fs from "fs";
import * as os from "os";

interface Round {
    id: number,
    highestRed: number,
    highestGreen: number,
    highestBlue: number
}

/**
 * Processes the input data file into an array of round data
 * Runtime: looping all n lines containing m entries, and each entry is run against one comparison: O(nm)
 * Space: each row of the data file results in 4 ints being stored: O(4n)
 * @param {string} inputFilePath Path of input file
 * @returns {Round[]} Array of round data, where each entry has a round's ID, and highest red, green, blue values
 */
function processInput(inputFilePath: string): Round[] {
    let lines = fs.readFileSync(inputFilePath).toString().split(os.EOL);

    let output: Round[] = [];

    for (let line of lines) {
        if (line === "") continue;

        let components = line.split(/;|:|,/g);

        // get round ID
        let roundId = parseInt(components[0].substring(5));

        // running maximums
        let highestRed = 0;
        let highestGreen = 0;
        let highestBlue = 0;

        for (let i = 1; i < components.length; i++) {
            let info = components[i].split(" ");

            switch (info[2]) {
                case "red":
                    if (parseInt(info[1]) > highestRed) {
                        highestRed = parseInt(info[1]);
                    }
                    break;
                case "green":
                    if (parseInt(info[1]) > highestGreen) {
                        highestGreen = parseInt(info[1]);
                    }
                    break;
                case "blue":
                    if (parseInt(info[1]) > highestBlue) {
                        highestBlue = parseInt(info[1]);
                    }
                    break;
            }
        }

        output.push({ id: roundId, highestRed: highestRed, highestGreen: highestGreen, highestBlue: highestBlue });
    }

    return output;
}

/**
 * Identifies rounds where the data shows the guess is possible, as equal or less red/green/blue were present then guessed
 * Runtime: for each n row, a comparison is run: O(n)
 * Space: in the worse case scenario where all rounds were possible, an int will be stored for each: O(n)
 * @param {Round[]} data Array of round data
 * @param {number} redLimit The number of red guessed
 * @param {number} greenLimit The number of green guessed
 * @param {number} blueLimit The number of blue guessed
 * @returns {number[]} Array of round IDs where the guess is possible given the data
 */
function identifyPossible(data: Round[], redLimit: number, greenLimit: number, blueLimit: number): number[] {
    let output: number[] = [];

    for (let round of data) {
        if (redLimit >= round.highestRed && greenLimit >= round.highestGreen && blueLimit >= round.highestBlue) {
            output.push(round.id);
        }
    }

    return output;
}

/**
 * Sums the numbers in an array
 * Runtime: O(n) for length n input
 * Space: O(1) for running sum
 * @param {number[]} input Array of numbers to sum
 * @returns {number} Sum of numbers from `input`
 */
function sumArray(input: number[]): number {
    let sum = 0;

    for (let number of input) {
        sum += number;
    }

    return sum;
}

/**
 * Runtime: O(nm) data extraction followed by O(n) data processing followed by O(n) to package result: O(nm + 2n)
 * Space: O(4n) data extraction followed by O(n) data processing followed by O(1) to package result: O(5n + 1)
 */
function solve(inputFilePath: string): number {
    return sumArray(identifyPossible(processInput(inputFilePath), 12, 13, 14));
}

// --- tests ---

function testProcessInput(): void {
    let expected = [
        { id: 1, highestRed: 4, highestGreen: 2, highestBlue: 6 },
        { id: 2, highestRed: 1, highestGreen: 3, highestBlue: 4 },
        { id: 3, highestRed: 20, highestGreen: 13, highestBlue: 6 },
        { id: 4, highestRed: 14, highestGreen: 3, highestBlue: 15 },
        { id: 5, highestRed: 6, highestGreen: 3, highestBlue: 2 }
    ];

    let results = processInput("sample.txt");

    for (let i = 0; i < expected.length; i++) {
        console.assert(expected[i].id === results[i].id && expected[i].highestRed === results[i].highestRed && expected[i].highestGreen === results[i].highestGreen && expected[i].highestBlue === results[i].highestBlue, "Failed test: processInput() on id: " + expected[i].id + " (expected) vs " + results[i].id + " (actual), highestRed: " + expected[i].highestRed + " (expected) vs " + results[i].highestRed + " (actual), highestGreen: " + expected[i].highestGreen + " (expected) vs " + results[i].highestGreen + " (actual), highestBlue: " + expected[i].highestBlue + " (expected) vs " + results[i].highestBlue + " (actual)");
    }
}

function testIdentifyPossible(): void {
    let result = identifyPossible(processInput("sample.txt"), 12, 13, 14);
    let expected = [1, 2, 5];

    console.assert(result.toString() === expected.toString(), "Failed test: identifyPossible(): " + expected.toString() + " (expected) vs " + result.toString() + " (actual)");
}

function testSumArray(): void {
    let result = sumArray([1, 2, 5]);
    console.assert(result === 8, "Failed test: sumArray(): 8 (expected) vs " + result + " (actual)");
}

function testSolve(): void {
    let result = solve("sample.txt");
    console.assert(result === 8, "Failed test: solve(): 8 (expected) vs " + result + " (actual)");
}

function runTests(): void {
    testProcessInput();
    testIdentifyPossible();
    testSumArray();
    testSolve();
}

runTests();

// --- run ---

if (process.argv.length == 2) {
    console.log("please provide input file path");
} else {
    console.log(solve(process.argv[2]));
}