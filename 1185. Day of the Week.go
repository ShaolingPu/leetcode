//link: https://leetcode.com/problems/day-of-the-week/

/*
Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

 

Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"
Example 2:

Input: day = 18, month = 7, year = 1999
Output: "Sunday"
Example 3:

Input: day = 15, month = 8, year = 1993
Output: "Sunday"
 

Constraints:

The given dates are valid dates between the years 1971 and 2100.
*/

/*
Result:
Runtime: 0 ms, faster than 100.00% of Go online submissions for Day of the Week.
Memory Usage: 2 MB, less than 100.00% of Go online submissions for Day of the Week.
*/

func dayOfTheWeek(day int, month int, year int) string {
    day += 4
    days_of_month := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    day_of_week := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    day += (year - 1971) * 365;
    day += (year - 1969) / 4;
    
    for i := 0; i < month - 1; i ++ {
        day += days_of_month[i]
    }
    
    if year % 4 == 0 && year != 2100 && month > 2 {
        day ++
    }
    
    return day_of_week[day % 7]
}