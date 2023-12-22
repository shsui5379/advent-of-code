import * as fs from "fs";
import * as os from "os";

/**
 * Reads an input file, and splits it on new line
 * 
 * @param {string} path  The path of the input file
 * @returns {Array<string>} An array of the input file content split on new line
 */
export function inputToArray(path: string): string[] {
   try {
      return fs.readFileSync(path).toString().split(os.EOL);
   } catch {
      return [];
   }
}

export function test(): void {
   console.assert(inputToArray("").toString() == [].toString());
   console.assert(inputToArray("../../2022/day2/sampleInput.txt").toString() == ["A Y", "B X", "C Z"].toString());
}