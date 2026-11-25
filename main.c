#include <stdio.h>
#include <math.h>

// Zavdannya 1 (variant 6)
void task1(void)
{
    int i;
    double tf;
    for (i = 0; i <= 100; i++) {
        tf = 9.0*i/5 + 32;
        printf("%3d C = %6.2f F\n", i, tf);
    }
}

// Zavdannya 2 (variant 13)
void task2(void)
{
    int i;
    double k;
    printf("Vvedit kurs dolara (UAH): ");
    scanf("%lf", &k);

    if (k <= 0) {
        printf("Pomylka: kurs maye buty > 0\n");
        return;
    }

    for (i = 1; i <= 20; i++) {
        printf("%2d USD = %7.2f UAH\n", i, i*k);
    }
}

// Zavdannya 3 (variant 32)
void task3(void)
{
    int i, p2 = 2;
    double x, num = 1, den = 1;
    printf("Vvedit x: ");
    scanf("%lf", &x);

    for (i = 1; i <= 6; i++) {
        if (x - p2 == 0) {
            printf("Pomylka: dilennya na 0\n");
            return;
        }
        num *= x - (p2 - 1);
        den *= x - p2;
        p2 *= 2;
    }

    printf("Rezultat: %.4f\n", num/den);
}

// Zavdannya 4 (variant 69)
void task4(void)
{
    int day = 1, d20 = 0, d100 = 0;
    double d = 10, sum = 10, sum7 = 0;

    printf("a) Probig za 2..10 dni:\n");
    while (day < 10 || d <= 20 || sum <= 100) {
        day++;
        d = d*1.1;
        sum += d;

        if (day >= 2 && day <= 10) {
            printf("Den %d: %.2f km\n", day, d);
        }
        if (day == 7) {
            sum7 = sum;
        }
        if (d > 20 && d20 == 0) {
            d20 = day;
        }
        if (sum > 100 && d100 == 0) {
            d100 = day;
        }
    }

    printf("b) Sumarnyy shlyakh za 7 dniv: %.2f km\n", sum7);
    printf("v) Bilshe 20 km na %d den\n", d20);
    printf("g) Sumarnyy probig > 100 km na %d den\n", d100);
}

// Zavdannya 5 (variant 130)
void task5(void)
{
    int n, m, ok = 1;
    double x, res;
    printf("Vvedit verkhnyu mezhu m (>= 2): ");
    scanf("%d", &m);

    if (m < 2) {
        printf("Pomylka: m maye buty >= 2\n");
        return;
    }

    for (n = 2; n <= m; n += 2) {
        x = n;
        res = x/12 + x*x/8 + x*x*x/24;
        if (fabs(res - round(res)) > 0.0001) {
            printf("Dlya n = %d chyslo %.4f ne ye tsilym\n", n, res);
            ok = 0;
            break;
        }
    }

    if (ok) {
        printf("Tak, dlya vsikh parnykh n vid 2 do %d vyraz ye tsilym\n", m);
    }
}

// Zavdannya 6 (variant 221)
void task6(void)
{
    int n = 0, sign = 1;
    double eps, p2 = 1, a;
    printf("Vvedit eps (> 0): ");
    scanf("%lf", &eps);

    if (eps <= 0) {
        printf("Pomylka: eps maye buty > 0\n");
        return;
    }

    do {
        n++;
        sign = -sign;
        p2 *= 2;
        a = (sign*n)/p2;
        printf("a%d = %.4f\n", n, a);
    } while (fabs(a) >= eps);

    printf("Naymenshyy nomer n = %d\n", n);
}

// Zavdannya 7 (variant 68)
void task7(void)
{
    int m = 0, m30 = 0, m1200 = 0;
    double sum = 1000, inc;

    printf("a) Pryrist vkladu za 1..10 misyatsi:\n");
    do {
        m++;
        inc = sum*0.012;
        sum += inc;

        if (m <= 10) {
            printf("Misyats %2d: +%.2f hrn\n", m, inc);
        }
        if (m >= 3 && m <= 12) {
            printf("Suma cherez %2d mis.: %.2f hrn\n", m, sum);
        }
        if (inc > 30 && m30 == 0) {
            m30 = m;
        }
        if (sum > 1200 && m1200 == 0) {
            m1200 = m;
        }
    } while (m < 12 || inc <= 30 || sum <= 1200);

    printf("v) Pryrist > 30 hrn za %d misyats\n", m30);
    printf("g) Vklad > 1200 hrn cherez %d misyatsiv\n", m1200);
}

// Zavdannya 8 (variant 237)
void task8(void)
{
    double a, b, h, x, res;
    printf("Vvedit a, b, h: ");
    scanf("%lf %lf %lf", &a, &b, &h);

    if (h <= 0 || a > b) {
        printf("Pomylka: nevirnyy vidrizok abo krok\n");
        return;
    }

    x = a;
    printf("x\t\tF(x)\n");
    while (x <= b + 0.0001) {
        if (fabs(cos(x/2)) < 0.0001) {
            printf("%.3f\t\tne vyznacheno\n", x);
        } else {
            res = 2*tan(x/2) + 1;
            printf("%.3f\t\t%.3f\n", x, res);
        }
        x += h;
    }
}

// Zavdannya 9 (variant 174)
void task9(void)
{
    int x, count = 0;
    long long sum = 0;
    printf("Vvodte nevidyemni tsili chysla (kinets - vidyemne): ");
    scanf("%d", &x);

    if (x < 0) {
        printf("Poslidovnist porozhnya\n");
        return;
    }

    while (x >= 0) {
        sum += x;
        count++;
        scanf("%d", &x);
    }

    printf("Serednye aryfmetychne: %.2f\n", (double)sum/count);
}

// Zavdannya 10 (variant 165)
void task10(void)
{
    long long n;
    int m, i, sum = 0;
    printf("Vvedit naturalne chyslo n ta kilkist tsyfr m: ");
    scanf("%lld %d", &n, &m);

    if (n <= 0 || m <= 0) {
        printf("Pomylka: n i m mayut buty > 0\n");
        return;
    }

    for (i = 0; i < m && n > 0; i++) {
        sum += n%10;
        n /= 10;
    }

    printf("Suma ostannikh %d tsyfr: %d\n", m, sum);
}

int main()
{
    int choice = -1;

    while (choice != 0) {
        printf("\n1 - Zavdannya 1\n");
        printf("2 - Zavdannya 2\n");
        printf("3 - Zavdannya 3\n");
        printf("4 - Zavdannya 4\n");
        printf("5 - Zavdannya 5\n");
        printf("6 - Zavdannya 6\n");
        printf("7 - Zavdannya 7\n");
        printf("8 - Zavdannya 8\n");
        printf("9 - Zavdannya 9\n");
        printf("10 - Zavdannya 10\n");
        printf("0 - Vykhid\n");
        printf("Vybir: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            case 10: task10(); break;
            case 0: printf("Vykhid\n"); break;
            default: printf("Nevirnyy nomer\n");
        }
    }

    return 0;
}
