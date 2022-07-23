#include <stdio.h>
void field();
void ball();

enum direction {
    MV, OUT, WIN
};

int main() {
    int button;
    int rr1 = 3, rr2 = 4, rr3 = 5;
    int rrx = 2;
    int rl1 = 7, rl2 = 8, rl3 = 9;
    int rlx = 78;
    int ballX = 41;
    int ballY = 13;
    int ballX_s = 41;
    int ballY_s = 13;
    int scp1 = 0;
    int scp2 = 0;
    int v_x = -2;
    int v_y = -1;
    int Height = 25;
    int winsc = 21;
    enum direction dir;
    dir = MV;
    while (1) {
        switch (dir) {
            case MV: if (ballX != 1 && ballY != 79) {
                if (ballY == 1 || ballY == Height - 1) {
                v_y = -v_y;
            }
                if (ballX == rlx - 1 && (ballY == rl1 || ballY == rl2 || ballY == rl3)) {
                v_x = -v_x;
            }
                if (ballX == rrx + 1 && (ballY == rr1 || ballY == rr2 || ballY == rr3)) {
                  v_x = -v_x;
            }
                ballX += v_x;
                ballY += v_y;
                if ((ballX <= 1) || (ballX >= 79)) {
                    dir = OUT;
                }
            } break;
            case OUT:
                if (ballX == 1) {
                    scp2 = scp2 + 1;
                }
                if (ballX == 79) {
                    scp1 = scp1 +1;
                }
                ballX = ballX_s;
                ballY = ballY_s;
                v_y = -v_y;
                v_x = -v_x;
                dir = MV;
                if ((scp1 == winsc) | (scp2 == winsc)) {
                    dir = WIN;
                } break;
            case WIN:
                if (scp1 == winsc || scp2 == winsc) {
                    if (scp1 == winsc) {
                        printf("\33[0d\33[2J");
                        printf("\n\tPLAYER ONE IS WON BY %d TO %d.!\n\t\tCONGRATULATIONS!!!\n", scp1, scp2);
                        return 1;
                } else if (scp2 == winsc) {
                    printf("\33[0d\33[2J");
                    printf("\n\tPLAYER TWO IS WON BY %d TO %d.!\n\t\tCONGRATULATIONS!!!\n", scp2, scp1);
                    return 1;
                }
            }
        }
        field(rr1, rr2, rr3, rrx, rl1, rl2, rl3, rlx, ballX, ballY, Height, scp1, scp2);
        printf("\t                Player_1 %d      -      Player_2 %d                \n", scp1, scp2);
        button = getchar();
        if ((button == 97 || button == 65) && rr1 != 1) {
            rr1--;
            rr2--;
            rr3--;
            }
        if ((button == 122 || button == 90) && rr3 != 24) {
            rr1++;
            rr2++;
            rr3++;
        }
        if ((button == 107 || button == 75) && rl1 != 1) {
            rl1--;
            rl2--;
            rl3--;
        }
        if ((button == 109 || button == 77) && rl3 != 24) {
            rl1++;
            rl2++;
            rl3++;
        }
    }
}
void field(int rr1, int rr2, int rr3, int rrx, int rl1, int rl2, int rl3, int rlx, int ballX, int ballY) {
    int Height = 25, Wildth = 80;
    char border = '!';
    char border2 = '-';
    char space = ' ';
    char rocket = '|';
    char line = 'l';
    char ball = 'o';
    printf("\33[0d\33[2J");
    for (int y = 0; y <= Height; y++) {
        for (int x = 0; x <= Wildth; x++) {
            if ((y == 0) || (y == Height)) {
                printf("%c", border2);
            } else {
                if ((x == 0) || (x == Wildth)) {
                    printf("%c", border);
                } else if ((rr1 == y || rr2 == y || rr3 == y) && (rrx == x)) {
                    printf("%c", rocket);
                } else if ((rl1 == y || rl2 == y || rl3 == y) && (rlx == x)) {
                    printf("%c", rocket);
                } else if (ballX == x && ballY == y) {
                    printf("%c", ball);
                } else if (x == 40 && y % 2 == 1) {
                    printf("%c", line);
                } else {
                    printf("%c", space);
                }
            }
        }
        printf("\n");
    }
}
