/**
 * Takes part 1 as base
 * But instead of summing logged IDs, 
 * we instead want to sum up all the products of each round's highest red/green/blue
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
 * Get every round's product of highest red/green/blue
 * Runtime: for each of the n rounds, one computation is done: O(n)
 * Space: each of the n rounds lead to one int being stored: O(n)
 * @param {Round[]} data Array of round data
 * @returns {number[]} Array of every round's product of highest red/green/blue
 */
function calculatePowers(data: Round[]): number[] {
    let output: number[] = [];

    for (let round of data) {
        output.push(round.highestRed * round.highestGreen * round.highestBlue);
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
    return sumArray(calculatePowers(processInput(inputFilePath)));
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

function testCalculatePowers(): void {
    let result = calculatePowers(processInput("sample.txt"));
    let expected = [48, 12, 1560, 630, 36];

    console.assert(result.toString() === expected.toString(), "Failed test: calculatePowers(): " + expected.toString() + " (expected) vs " + result.toString() + " (actual)");
}

function testSumArray(): void {
    let result = sumArray([1, 2, 5]);
    console.assert(result === 8, "Failed test: sumArray(): 8 (expected) vs " + result + " (actual)");
}

function testSolve(): void {
    let result = solve("sample.txt");
    console.assert(result === 2286, "Failed test: solve(): 2286 (expected) vs " + result + " (actual)");
}

function runTests(): void {
    testProcessInput();
    testCalculatePowers();
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