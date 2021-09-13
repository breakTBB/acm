import math

man = 258
female = 216
man_minority = 64
female_minority = 40
people = man + female
minority = man_minority + female_minority
not_minority = people - minority

p_man = man / people
p_female = female / people
p_man_minority = man_minority / man
p_man_not_minority = 1 - p_man_minority
p_female_minority = female_minority / female
p_female_not_minority = 1 - p_female_minority
p_minority = minority / people
p_not_minority = 1 - p_minority

E_gender = - p_man * math.log(p_man) - p_female * math.log(p_female)
E_minority = p_man * (
        - p_man_minority * math.log(p_man_minority)
        - p_man_not_minority * math.log(p_man_not_minority)
) + p_female * (-p_female_minority * math.log(p_female_minority)
                - p_female_not_minority * math.log(p_female_not_minority)
                )
GAIN = E_gender - E_minority
Split_Info = -p_minority * math.log(p_minority) - p_not_minority * math.log(p_not_minority)
Gain_Ratio = GAIN / Split_Info


print(Gain_Ratio)
