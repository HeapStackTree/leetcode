#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

#define LIMIT 100000001
class Solution {
public:
    int countPrimes(int n) {
        return P(n, LIMIT);
    }
    int P(int n, int max) {
        static bool mark[LIMIT];
        static int a[LIMIT];
        if (n <= 2) {
            return 0;
        }
        if (n == 3){
            return 1;
        }
        if (n%2 != 0){
            return P(n-1,max);
        }
        if (a[n] != 0) {
            return a[n];
        }
        int result = 1;
        int root = sqrt(max);
        for (int i = 3; i < max; i += 2) {
            if (!mark[i]) {
                result++;
                if (i <= root) {
                    for (int j = i * i; j < max; j += 2 * i) {
                        mark[j] = true;
                    }
                }
            }
            a[i+1]=result;
        }
        return a[n];
    }
};

class Solution2 {
public:
    int countPrimes(int n) {
        size_t isize = (n + 1) * sizeof(int);
        int *primesInt = (int *)malloc(isize);
        memset(primesInt, 0, isize);
        primesInt[0] = 3;
        int end = 3;
        int pos = 1;
        if (n <= 2) {
            return 0;
        }
        if (n > end + 2) {  //有新的数据范围要判断
            int newStart = end + 2;
            int newEnd = (n & 0x1) == 1 ? n - 2 : n - 1;

            size_t bsize = (n + 1) * sizeof(bool);
            bool *primesChecks = (bool *)malloc(bsize); //准备判断新数据范围的所有奇数
            memset(primesChecks, 0, bsize);

            int limit = (int) sqrt(newEnd);
            //用已记录的质数筛一次新的数据范围
            for (int j = 0; j < pos; j++) {
                int i = primesInt[j];
                if (i <= limit) {
                    int next = i * i;
                    if (next < newStart) {
                        int divide = end / i;
                        divide += (divide & 0x1) == 1 ? 2 : 1;
                        next = i * divide;
                    }
                    for (int k = next; k <= newEnd; k += (i << 1)) {
                        primesChecks[k - newStart >> 1] = true;
                    }
                } else {
                    break;
                }
            }
            //用新数据范围内得到的质数继续筛除新数据范围
            for (int i = newStart; i <= newEnd; i += 2) {
                if (!primesChecks[i - newStart >> 1]) {
                    primesInt[pos++] = i; //筛的过程中，记录筛出的质数
                    if (i <= limit) {
                        //如果此质数在新范围内可筛，继续筛除新范围的质数
                        int divide = end / i;
                        divide += (divide & 0x1) == 1 ? 2 : 1;

                        for (int k = i * divide; k <= newEnd; k += (i << 1)) {
                            primesChecks[k - newStart >> 1] = true;
                        }
                    }
                }
            }
            //更新新的记录范围
            end = newEnd;
            free(primesChecks);
        }

        if (pos == 0 || n > primesInt[pos - 1]) {
            return pos + 1;
        } else {
            //如果是查询记录过范围的中间数，二分法查询
            int l = 0;
            int r = pos - 1;
            while (l < r) {
                int mid = l + (r - l >> 1);
                if (primesInt[mid] < n) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l + 1;
        }
        free(primesInt);
    }
};

class Solution3 {
public:
    int countPrimes(int n) {
        return count_prime_sieve(2, n-1);
    }
    long count_prime_sieve(long min_num, long max_num) {
        size_t msize = (max_num + 1) * sizeof(bool);
        bool *isprime = (bool *)malloc(msize);
        memset(isprime, 1, msize);
        size_t psize = (max_num + 1) * sizeof(long);
        long *primes = (long *)malloc(psize);
        memset(primes, 0, psize);
        long cnt = 0;
        for (long long i = 2; i <= max_num; i++) {
            if (isprime[i]) {
                primes[cnt++] = i;
            }
            for (long long j = 0; j < cnt && i * primes[j] <= max_num; j++) {
                isprime[i * primes[j]] = false;
            }
        }
        long min_cnt = 0;
        for (long i = 0; i < cnt; i++) {
            if (primes[i] >= min_num) {
                min_cnt = i;
                break;
            }
        }
        free(primes);
        free(isprime);
        return cnt - min_cnt;
    }
};

void count_prime_solution1(long long min_num, long long max_num) {
    clock_t start = clock();
    Solution sol;
    long long prime_count = sol.countPrimes(max_num + 1) - sol.countPrimes(min_num);
    clock_t end = clock();
    long long elapsed = (long long)(end - start) * 1000 / CLOCKS_PER_SEC;
    printf("Solution costs %lldms, finds %lld prime numbers in [%lld, %lld]\n", elapsed, prime_count, min_num, max_num);
}

void count_prime_solution2(long long min_num, long long max_num) {
    clock_t start = clock();
    Solution2 sol;
    long long prime_count = sol.countPrimes(max_num + 1) - sol.countPrimes(min_num);
    clock_t end = clock();
    long long elapsed = (long long)(end - start) * 1000 / CLOCKS_PER_SEC;
    printf("Solution2 costs %lldms, finds %lld prime numbers in [%lld, %lld]\n", elapsed, prime_count, min_num, max_num);
}


void count_prime_solution3(long long min_num, long long max_num) {
    clock_t start = clock();
    Solution3 sol;
    long long prime_count = sol.countPrimes(max_num + 1) - sol.countPrimes(min_num);
    clock_t end = clock();
    long long elapsed = (long long)(end - start) * 1000 / CLOCKS_PER_SEC;
    printf("Solution3 costs %lldms, finds %lld prime numbers in [%lld, %lld]\n", elapsed, prime_count, min_num, max_num);
}

int main(int argc, char **argv) {
    long long min_mum = 2, max_mum = 100000000;
    if (argc == 2) {
        max_mum = atoll(argv[1]);
    } else if (argc == 3) {
        min_mum = atoll(argv[1]);
        max_mum = atoll(argv[2]);
    }
    count_prime_solution3(min_mum, max_mum);
    count_prime_solution2(min_mum, max_mum);
    count_prime_solution1(min_mum, max_mum);
    return 0;
}