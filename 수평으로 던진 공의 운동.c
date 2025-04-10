#include <stdio.h>
#include <math.h>

#define G 9.8
#define PI 3.14159265358979

int main() {
    double v0, angle_deg;
    double vx, vy;
    double h_max, t_peak, t_total, range;
    double vx_final, vy_final, v_final;

    printf("초기 속도 (m/s)를 입력하세요.: ");
    scanf_s("%lf", &v0);

    printf("발사각 (도)를 입력하세요.: ");
    scanf_s("%lf", &angle_deg);

    double angle_rad = angle_deg * PI / 180.0;

    vx = v0 * cos(angle_rad);
    vy = v0 * sin(angle_rad);

    h_max = (vy * vy) / (2 * G);

    t_peak = vy / G;

    t_total = 2 * t_peak;


    range = vx * t_total;

    vx_final = vx;          
    vy_final = -vy;          
    v_final = sqrt(vx_final * vx_final + vy_final * vy_final); 

 
    printf("\n==== 계산 결과 ====\n");
    printf("1) 초기 속도 성분: Vx = %.2f m/s, Vy = %.2f m/s\n", vx, vy);
    printf("2) 최고점 높이: %.2f m\n", h_max);
    printf("3) 최고점 도달 시간: %.2f s\n", t_peak);
    printf("4) 수평 이동 거리: %.2f m\n", range);
    printf("5) 지면 도달 시 속도 성분: \nVx = %.2f m/s \nVy = %.2f m/s \nV = %.2f m/s\n", vx_final, vy_final, v_final);

    return 0;
}