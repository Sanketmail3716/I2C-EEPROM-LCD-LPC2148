

#define rs 17
#define rw 18
#define en 19

#define d4 20
#define d5 21
#define d6 22
#define d7 23

#define lcdpin ((1<<d4)|(1<<d5)|(1<<d6)|(1<<d7)|(1<<rs)|(1<<rw)|(1<<en))

void lcd_init(void);
void cmd(unsigned char);
void lcddata(unsigned char);
void str(char *);
