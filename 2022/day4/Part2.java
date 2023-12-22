import java.io.*;

public class Part2 {
    // main problem is to find whether the ranges have any overlap
    // an overlap exists if range1's start or end is inside range2
    // or if range2's start or end is inside range1
    // this check will be a constant time check

    public static int solve(String inputPath) throws Exception {
        File inputfile = new File(inputPath);
        BufferedReader br = new BufferedReader(new FileReader(inputfile));

        String currentline;
        int counter = 0;

        while ((currentline = br.readLine()) != null) {
            String[] intervals = currentline.split(",");

            String[] elf1 = intervals[0].split("-");
            String[] elf2 = intervals[1].split("-");

            int elf1Start = Integer.parseInt(elf1[0]);
            int elf1End = Integer.parseInt(elf1[1]);

            int elf2Start = Integer.parseInt(elf2[0]);
            int elf2End = Integer.parseInt(elf2[1]);

            if (elf1Start >= elf2Start && elf1Start <= elf2End || elf1End >= elf2Start && elf1End <= elf2End
                    || elf2Start >= elf1Start && elf2Start <= elf1End || elf2End >= elf1Start && elf2End <= elf1End) {
                counter++;
            }
        }

        br.close();

        return counter++;
    }

    public static void main(String[] args) {
        try {
            assert solve("sample.txt") == 4 : "sample test case";

            if (args.length < 1) {
                System.out.println("provide input file path");
            } else {
                System.out.println(solve(args[0]));
            }
        } catch (Exception e) {
            System.out.println("test case failed");
        }
    }
}