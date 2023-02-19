from sys import getsizeof
import time
import random


for i in range(9):
    start_time = time.perf_counter_ns()
    test_dict = {}
    n_elements = 10**i
    for _ in range(1, n_elements+1):
        key = random.randint(0, 100000)
        value = random.randint(0, 100000)
        test_dict[key] = value
    end_time = time.perf_counter_ns()
    time_diff = (end_time - start_time)
    # количество элементов - размер dict - время заполнения в наносекундах
    print(n_elements, getsizeof(test_dict), int(time_diff))
