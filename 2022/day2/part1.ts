import * as InputUtil from "../commons/ts/inputUtils"

/**
 * for each input, determine the score, and add it to the running sum
 * 
 * to determine the score, one approach is to have a preloaded 2D array table w/ pt values for the 9 different scenarios
 * Runtime: 2-op lookup
 * Space: have to store 9 values
 * 
 * map approach
 * X: beats C, 1 pt
 * Y: beats A, 2 pt
 * Z: beats B, 3 pt
 * runtime: 1 op for lookup, 1 op for determine if win, (worst case) 1 op for determining if tie, 1 op for updating score
 * space: map of 3 values
 * Runtime makes more operations, but can save space when N gets large (in a universe where rock paper scissors has N moves)
 */

const rules = {
   X: {
      beats: "C",
      scores: 1
   },
   Y: {
      beats: "A",
      scores: 2
   },
   Z: {
      beats: "B",
      scores: 3
   }
};

// runtime: O(n), where n is number of lines of input
// space: O(1)
function solve(inputFilePath: string): number {
   const input: string[] = InputUtil.inputToArray(inputFilePath);

   let score: number = 0;

   // N iterations of constant work, O(N)
   for (let round of input) {
      const playerMove: string = round[2];
      const opponentMove: string = round[0];

      score += rules[playerMove as keyof typeof rules].scores;

      if (rules[playerMove as keyof typeof rules].beats == opponentMove) { // player beats opponent
         score += 6;
      } else if (playerMove.charCodeAt(0) - 23 == opponentMove.charCodeAt(0)) { // tie
         score += 3;
      }
   }

   return score;
}

console.assert(solve("sampleInput.txt") == 15);

if (process.argv.length == 2) {
   console.log("please provide input file path");
} else {
   console.log(solve(process.argv[2]));
}
