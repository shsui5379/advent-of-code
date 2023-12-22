import java.io.*;

public class Part1 {
  // main problem is to find whether one of the time ranges is a subset of the
  // other time range
  // if we suppose range 1 is a-b
  // and range 2 is c-d
  // range 1 is subset of range 2 if a >= c and b <= d
  // range 2 is subset of range 1 if a <= c amd b >= d
  // else, no subsets
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

      if (elf1Start >= elf2Start && elf1End <= elf2End || elf1Start <= elf2Start && elf1End >= elf2End) {
        counter++;
      }
    }

    br.close();

    return counter++;
  }

  public static void main(String[] args) {
    try {
      assert solve("sample.txt") == 2 : "sample test case";

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