#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x1, y1, x2, y2;
} Rect;

Rect rects[1005];
int xs[4025];  // 4025个元素（足够容纳4024个坐标点）
int ys[4025];

int **grid;     // 动态分配的二维网格

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int get_index(int *arr, int len, int val) {
    int left = 0, right = len - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == val) return mid;
        if (arr[mid] < val) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    FILE *fin = fopen("constr.in", "r");
    FILE *fout = fopen("constr.out", "w");
    
    int N, a, b;
    fscanf(fin, "%d %d %d", &N, &a, &b);

    int xs_cnt = 0, ys_cnt = 0;

    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d %d %d %d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);
        xs[xs_cnt++] = rects[i].x1;
        xs[xs_cnt++] = rects[i].x2;
        ys[ys_cnt++] = rects[i].y1;
        ys[ys_cnt++] = rects[i].y2;
    }
    
    // 添加边界坐标
    xs[xs_cnt++] = 0;
    xs[xs_cnt++] = a;
    ys[ys_cnt++] = 0;
    ys[ys_cnt++] = b;    

    // 排序坐标
    qsort(xs, xs_cnt, sizeof(int), cmp);
    qsort(ys, ys_cnt, sizeof(int), cmp);

    // 离散化：只保留不重复的坐标
    int wx = 0, wy = 0;
    // 正确的离散化方法：从第一个坐标开始
    xs[wx++] = xs[0];
    for (int i = 1; i < xs_cnt; i++) {
        if (xs[i] != xs[i-1]) {
            xs[wx++] = xs[i];
        }
    }
    ys[wy++] = ys[0];
    for (int i = 1; i < ys_cnt; i++) {
        if (ys[i] != ys[i-1]) {
            ys[wy++] = ys[i];
        }
    }
    
    // 动态分配二维网格
    grid = (int **)malloc(wx * sizeof(int *));
    for (int i = 0; i < wx; i++) {
        grid[i] = (int *)malloc(wy * sizeof(int));
        for (int j = 0; j < wy; j++) {
            grid[i][j] = 0;
        }
    }

    // 标记被征收的区域
    for (int k = 0; k < N; k++) {
        int x_start = get_index(xs, wx, rects[k].x1);
        int x_end = get_index(xs, wx, rects[k].x2);
        int y_start = get_index(ys, wy, rects[k].y1);
        int y_end = get_index(ys, wy, rects[k].y2);

        // 确保坐标有效（理论上不会为-1，但预防越界）
        if (x_start == -1 || x_end == -1 || y_start == -1 || y_end == -1) {
            continue;
        }

        for (int i = x_start; i < x_end; i++) {
            for (int j = y_start; j < y_end; j++) {
                grid[i][j] = 1;
            }
        }
    }

    // 计算征收面积
    long long total_area = 0;
    int x0 = get_index(xs, wx, 0);
    int x1 = get_index(xs, wx, a);
    int y0 = get_index(ys, wy, 0);
    int y1 = get_index(ys, wy, b);

    // 确保坐标有效
    if (x0 == -1 || x1 == -1 || y0 == -1 || y1 == -1) {
        total_area = 0;
    } else {
        for (int i = x0; i < x1; i++) {
            for (int j = y0; j < y1; j++) {
                if (grid[i][j]) {
                    total_area += (long long)(xs[i+1] - xs[i]) * (ys[j+1] - ys[j]);
                }
            }
        }
    }

    fprintf(fout, "%lld\n", total_area);
    
    // 释放内存
    for (int i = 0; i < wx; i++) {
        free(grid[i]);
    }
    free(grid);

    fclose(fin);
    fclose(fout);
    return 0;
}

//4 10 10
0 0 5 5
5 -2 15 3
8 8 15 15
-2 10 3 15