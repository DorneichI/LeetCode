class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        daysSince = 0
        daysSince += 365 * (year - 1971)
        daysSince += (year - 1969) // 4
        
        if month > 2:
            if year % 4 == 0:
                daysSince += 1 
            if year % 4 == 0 and year % 100 == 0:
                daysSince -= 1
            if year % 4 == 0 and year % 100 == 0 and year % 1000 == 0:
                daysSince += 1
            
        if month == 2:
            daysSince += 31
        elif month == 3:
            daysSince += 59
        elif month == 4:
            daysSince += 90
        elif month == 5:
            daysSince += 120
        elif month == 6:
            daysSince += 151
        elif month == 7:
            daysSince += 181
        elif month == 8:
            daysSince += 212
        elif month == 9:
            daysSince += 243
        elif month == 10:
            daysSince += 273
        elif month == 11:
            daysSince += 304
        elif month == 12:
            daysSince += 334
            
            
        daysSince += day
        
        daysSince = daysSince % 7
        if daysSince == 1:
            return 'Friday'
        elif daysSince == 2:
            return 'Saturday'
        elif daysSince == 3:
            return 'Sunday'
        elif daysSince == 4:
            return 'Monday'
        elif daysSince == 5:
            return 'Tuesday'
        elif daysSince == 6:
            return 'Wednesday'
        elif daysSince == 0:
            return 'Thursday'
        else:
            return 'aaaa'
