import * as InputUtil from "../commons/ts/inputUtils"

/**
 * for each input, determine the score, and add it to the running sum
 * the input tells if you're to lose, win or tie, and the opponent's move
 * 
 * 2D array implementation still works here
 * rows for win/tie/lose, column for opponent move
 * same runtime and space complexity
 * 
 * map implementation still works here, but the map needs some change
 * A: beats map[C], scores 1
 * B: beats map[A], scores 2
 * C: beats map[B], scores 3
 * 2 hops will make you lose
 * 1 hop will make you win
 * 0 hops will make you tie
 * runtime: 1 op for lookup, up to 3 op determining win/lose/tie, up to 2 op to find appropriate score
 * space: 6 items
 */

const rules = {
   X: {
      A: 3,
      B: 1,
      C: 2
   },
   Y: {
      A: 4,
      B: 5,
      C: 6
   },
   Z: {
      A: 8,
      B: 9,
      C: 7
   }
};

// N iterations of constant number of ops, so O(N) time complexity
// where N is the number of input lines
// O(1) space complexity
function solve(inputFilePath: string): number {
   const input: string[] = InputUtil.inputToArray(inputFilePath);

   let score: number = 0;

   for (let round of input) {
      const playerMove: string = round[2];
      const opponentMove: string = round[0];

      score += rules[playerMove as keyof typeof rules][opponentMove as keyof typeof rules.X];
   }

   return score;
}

console.assert(solve("sampleInput.txt") == 12);

if (process.argv.length == 2) {
   console.log("please provide input file path");
} else {
   console.log(solve(process.argv[2]));
}
