g++ -std=c++11 MainTest.cpp -o Lab07 &&
for i in {0..9}; do
    ./Lab07 "Inputs/input_$i.txt" > "result_$i.txt"
done

for i in {0..9}; do
    python3 GradingScript.py "result_$i.txt" "Outputs/output_$i.txt"
    # diff "result_$i.txt" "Outputs/output_$i.txt" | grep "^>" | wc -l
    rm "result_$i.txt"
done

rm Lab07 test_result