#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int isLeap(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    if (month == 2) return isLeap(year) ? 29 : 28;
    return 0;
}

int isValid(Date date) {
    return date.month >= 1 && date.month <= 12 && date.day >= 1 && date.day <= daysInMonth(date.month, date.year);
}

int countDays(Date start, Date end) {
    int days = 0;
    while (start.year < end.year || (start.year == end.year && start.month < end.month) || 
           (start.year == end.year && start.month == end.month && start.day < end.day)) {
        start.day++;
        days++;
        if (start.day > daysInMonth(start.month, start.year)) {
            start.day = 1;
            start.month++;
            if (start.month > 12) {
                start.month = 1;
                start.year++;
            }
        }
    }
    return days;
}

int getWeekday(Date date) {
    int d = date.day, m = date.month, y = date.year;
    if (m < 3) { m += 12; y--; }
    int k = y % 100, j = y / 100;
    return (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
}

const char* weekdayToStr(int day) {
    const char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    return days[day];
}

int main() {
    Date date1 = {1, 1, 2020};
    Date date2 = {31, 12, 2020};

    if (isValid(date1) && isValid(date2)) {
        printf("Days between: %d\n", countDays(date1, date2));
    } else {
        printf("Invalid date\n");
    }

    printf("Weekday for %d/%d/%d: %s\n", date1.day, date1.month, date1.year, weekdayToStr(getWeekday(date1)));

    return 0;
}
