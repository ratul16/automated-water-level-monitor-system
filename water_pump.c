/*
RB0 is Trig Pin
RB1 is Echo pin
RB2 is green led pin
RB3 is yellow led pin
RB4 is red led pin
RB5 is for motor
*/

int findDistance()
{
    int distance1 = 0;
    TMR1L = 0x0;
    TMR1H = 0x0;
    RB0_BIT = 1;
    delay_us(10);
    RB0_BIT = 0;
    T1CON.F0 = 1;
    while(RB1_BIT);
    T1CON.F0 = 0;
    distance1 = (TMR1L | (TMR1H<<8));
    distance1 = (distance1*0.034)/2;

    return distance1;
}

void main() {
int distance = 0;
TRISB = 0x02;

PORTB = 0x0;
TMR1L = 0x0;
TMR1H = 0x0;

while(1)
{
    distance = findDistance();
    if(distance >= 30)
    {
        RB2_BIT = 0;
        RB3_BIT = 0;
        RB4_BIT = 1;
        RB5_BIT = 1;

        while(distance > 10)
        {
            if(distance >= 30)
            {
                RB2_BIT = 0;
                RB3_BIT = 0;
                RB4_BIT = 1;
                RB5_BIT = 1;
            }
            else if(distance >= 20 && distance <= 29)
            {
                RB2_BIT = 0;
                RB3_BIT = 1;
                RB4_BIT = 1;
                RB5_BIT = 1;
            }
            else if(distance >=11 && distance <=19)
            {
                RB2_BIT = 1;
                RB3_BIT = 1;
                RB4_BIT = 1;
                RB5_BIT = 1;
            }
            else if(distance <=10 )
            {
                RB2_BIT = 1;
                RB3_BIT = 1;
                RB4_BIT = 1;
                RB5_BIT = 0;
            }
            distance = findDistance();

         }
    }
    else if(distance >= 20 && distance <= 29)
    {
        RB2_BIT = 0;
        RB3_BIT = 1;
        RB4_BIT = 1;
        RB5_BIT = 0;

    }
    else if(distance >=10 && distance <=19)
    {
        RB2_BIT = 1;
        RB3_BIT = 1;
        RB4_BIT = 1;
        RB5_BIT = 0;
    }
}

}