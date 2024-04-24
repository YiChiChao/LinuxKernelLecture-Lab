import matplotlib.pyplot as plt
import numpy as np

# 定義檔案路徑和 cache capacity 的值
file_paths = {
    1000: 'multi_search_time_cache1000.txt',
    500: 'multi_search_time_cache500.txt',
    250: 'multi_search_time_cache250.txt'
}

# 定義顏色和標記形狀
colors = ['r', 'g', 'b']
markers = ['o', 's', '^']  # 不同 cache capacity 使用不同形狀的點陣

# 讀取搜尋時間資料
def read_search_time_file(file_path):
    with open(file_path, 'r') as file:
        search_time_data = [float(line.strip()) for line in file]
    return np.array(search_time_data)

# 繪製點陣圖
def plot_search_time_scatter():
    plt.figure(figsize=(10, 6))  # 設置圖片大小
    
    for i, (capacity, file_path) in enumerate(file_paths.items()):
        search_time_data = read_search_time_file(file_path)
        hlist_size_start = 10
        hlist_size_end = capacity  # 使用對應的 cache capacity 作為 hlist size 的結束值
        hlist_sizes = np.arange(hlist_size_start, hlist_size_end + 1, 10)[::-1]  # 反轉 hlist_sizes 陣列
        
        plt.scatter(hlist_sizes, search_time_data[:len(hlist_sizes)], 
                    label=f'Cache Capacity={capacity}', 
                    color=colors[i], marker=markers[i])
    
    plt.xlabel('HList Size')
    plt.ylabel('Search Time (microseconds)')
    plt.title('Search Time vs. HList Size for Different Cache Capacities with Multiplication Method Hash Function')
    plt.legend()
    plt.grid(True)
    
    # 設置 x 軸刻度
    plt.xticks(np.arange(0, 1000 + 1, 50))  # 每 50 單位一個刻度
    
    plt.show()

# 主程式入口
if __name__ == '__main__':
    plot_search_time_scatter()
