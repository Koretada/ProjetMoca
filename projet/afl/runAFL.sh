0
# compile the example with instrumented code
# (seems required to enforce non 03 optimization to preserve crashes !)
echo "compile the pgm for AFL"
AFL_DONT_OPTIMIZE=1 afl-gcc -O0 *.c 

# launch the fuzzing campaign (ended by ^C)
echo "run AFL !"
AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1 afl-fuzz -i afl_in/ -o afl_out/ ./a.out @@
