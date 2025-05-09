/*

SORT 1:
$ time ./sort1 random5000.txt   : 0m0.078s
$ time ./sort1 random10000.txt  : 0m0.221s ~ 0m0.191s
$ time ./sort1 random50000.txt  : 0m6.148s ~ 0m6.108s
$

SORT 2:
$ time ./sort2 random5000.txt   : 0m0.027s


$ time ./sort2 random10000.txt  : 0m0.135s ~ 0m0.059s
real    0m0.078s
user    0m0.004s
sys     0m0.049s

$ time ./sort2 random50000.txt  : 0m0.823s
real    0m1.134s
user    0m0.028s
sys     0m0.227s


SORT 3:
$ time ./sort3 random5000.txt   : 0m0.068s
real    0m0.054s
user    0m0.019s
sys     0m0.023s

$ time ./sort3 random10000.txt  : 0m0.147s ~ 0m0.127s
real    0m0.152s
user    0m0.073s
sys     0m0.048s

$ time ./sort3 random50000.txt  : 0m3.373s ~ 0m2.728s
real    0m3.373s
user    0m1.877s
sys     0m0.205s

*/
