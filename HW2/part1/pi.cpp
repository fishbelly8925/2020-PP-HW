#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <vector>
#include <thread>
#include <string>
#include <pthread.h>
#include <climits>
#include <ctime>
#include <cmath>
#include <queue>
#include <set>
#include <numeric>
using namespace std;
using std::string;
using std::thread;

int thread_num;
long long n;
long long cnt;

void* pp(void* rank) {
    long local_rank = (long)rank;
    long iter_num = (local_rank < n % thread_num) ? n / thread_num + 1: n / thread_num;
    unsigned int seed = 0;

    float x, y;
    long local = 0;
    
    for (long i = 0; i < iter_num; i++) {
	
        x = (float)rand_r(&seed) / RAND_MAX;
        y = (float)rand_r(&seed) / RAND_MAX;
        if (x * x + y * y < 1) local++;
	
    }
    

    return (void*) local;
}


int main(int argc, char* argv[]) {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    pthread_t* ppthread;

    thread_num = stoi(argv[1], NULL, 10);
    n = stoll(argv[2], NULL, 10);
    ppthread = (pthread_t*) malloc(thread_num * sizeof(pthread_t));
    //pthread_mutex_init(&mutex, NULL);
    //srand(time(NULL));
    void * returnValue;

    for (long i = 0; i < thread_num; i++) {
        pthread_create(&ppthread[i], NULL, &pp, (void*)i);
    }

    for (int i = 0; i < thread_num; i++) {
        pthread_join(ppthread[i], &returnValue);
	cnt += (long) returnValue;
    }

    double ans = (double) cnt / (double) n;
    cout << setprecision(10) << ans * 4 << '\n';

    //pthread_mutex_destroy(&mutex);
    
    return 0;
}
