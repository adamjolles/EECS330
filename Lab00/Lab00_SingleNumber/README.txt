1: Compile MainTest to test data files
g++ -std=c++11 MainTest.cpp -o Lab00

2: Running the testing program
for i in {0..9}; do ./Lab00 Inputs/input_$i.txt >result_$i.txt; done

3: Comparing your result with expected output
for i in {0..9}; do python3 GradingScript.py result_$i.txt Outputs/output_$i.txt; done
If you see "Yes", then your program is correct. Or if you see "No", your program is incorrect.

4. Delete results files
for i in {0..9}; do rm result_$i.txt; done && rm test_result
rm Lab00