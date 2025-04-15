#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

#define G 9.8
#define DEG_TO_RAD(angle) ((angle) * M_PI / 180.0)

int main() {
    double V0, angleDeg, y0;

    // 사용자 입력
    printf("초기 속도 V0 (m/s): ");
    scanf_s("%lf", &V0);

    printf("발사 각도 (deg): ");
    scanf_s("%lf", &angleDeg);

    printf("초기 높이 y0 (m): ");
    scanf_s("%lf", &y0);

    // 각도를 라디안으로 변환
    double angleRad = DEG_TO_RAD(angleDeg);

    // 초기 속도의 수평/수직 성분
    double Vx0 = V0 * cos(angleRad);
    double Vy0 = V0 * sin(angleRad);

    printf("\n--- 초기 속도 성분 계산 ---\n");
    printf("Vx0 = V0 * cos(θ) = %.2f * cos(%.2f°) = %.2f m/s\n", V0, angleDeg, Vx0);
    printf("Vy0 = V0 * sin(θ) = %.2f * sin(%.2f°) = %.2f m/s\n", V0, angleDeg, Vy0);

    // (a) 낙하 시간: y = y0 + Vy0*t - 0.5*g*t^2 = 0
    double a = -0.5 * G;
    double b = Vy0;
    double c = y0;
    double discriminant = b * b - 4 * a * c;

    double t = 0.0;
    printf("\n--- (a) 낙하 시간 계산 ---\n");
    printf("공식: 0 = y0 + Vy0*t - 0.5*g*t^2 → 이차방정식 at² + bt + c = 0\n");
    printf("a = %.2f, b = %.2f, c = %.2f\n", a, b, c);
    printf("판별식 D = b² - 4ac = %.2f\n", discriminant);

    if (discriminant >= 0) {
        double t1 = (-b + sqrt(discriminant)) / (2 * a);
        double t2 = (-b - sqrt(discriminant)) / (2 * a);
        t = (t1 > 0) ? t1 : t2;
        printf("해 t1 = %.2f, t2 = %.2f → 사용: t = %.2f 초\n", t1, t2, t);
    }
    else {
        printf("❌ 해가 없습니다. (판별식 < 0)\n");
        return 1;
    }

    // (b) 수평 거리
    double x = Vx0 * t;
    printf("\n--- (b) 수평 거리 계산 ---\n");
    printf("x = Vx0 * t = %.2f * %.2f = %.2f m\n", Vx0, t, x);

    // (c) 최종 속도 성분
    double Vx_final = Vx0;
    double Vy_final = Vy0 - G * t;
    printf("\n--- (c) 최종 속도 성분 ---\n");
    printf("Vx = %.2f m/s (변하지 않음)\n", Vx_final);
    printf("Vy = Vy0 - g*t = %.2f - %.2f * %.2f = %.2f m/s\n", Vy0, G, t, Vy_final);

    // (d) 속도 크기
    double V_final = sqrt(Vx_final * Vx_final + Vy_final * Vy_final);
    printf("\n--- (d) 최종 속도 크기 ---\n");
    printf("V = sqrt(Vx² + Vy²) = sqrt(%.2f² + %.2f²) = %.2f m/s\n", Vx_final, Vy_final, V_final);

    // (e) 각도
    double angle_final_rad = atan2(Vy_final, Vx_final);
    double angle_final_deg = angle_final_rad * 180.0 / M_PI;
    printf("\n--- (e) 속도 벡터가 수평과 이루는 각도 ---\n");
    printf("θ = atan2(Vy, Vx) = atan2(%.2f, %.2f) = %.2f 도\n", Vy_final, Vx_final, angle_final_deg);

    return 0;
}