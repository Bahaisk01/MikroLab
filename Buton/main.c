/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/

#include "driverlib.h"
//******************************************************************************
//!
//!   Empty Project that includes driverlib
//!
//******************************************************************************
void main (void)
{
  WDTCTL = WDTPW | WDTHOLD;

  P2SEL &= ~BIT1;
  P2DIR &= ~BIT1; //P2 buton INPUT
  P2REN |= BIT1; //Pull Down-Up açıldı
  P2OUT |= BIT1; //Pull Up seçildi

  P1SEL &= ~BIT0; 
  P1DIR |= BIT0; //LED OUTPUT olarak ayarlandı
  P1OUT &= ~BIT0; // Başlangıç Outputu 0 olarak ayarlandı

  P1SEL &= ~BIT1;
  P1DIR &= ~BIT1;
  P1REN |= BIT1;
  P1OUT |= BIT1;
 
  P4SEL &= ~BIT7;
  P4DIR |= BIT7;
  P4OUT &= ~BIT7;

  /*while(1)
  {
    if ((P2IN&BIT3)== 1)
    {
        P1OUT |= BIT0;
    }
    else
    {
        P1OUT &= ~BIT0;
    }
  }
    */
    //Üst kısımdaki kodun sadece basılı tutunca çalışması gerekiyor
    while(1)
  {
    if (!(P2IN&BIT1))
    {
      __delay_cycles(50000);
      if (!(P2IN&BIT1))
      {
        P1OUT ^= BIT0;
        while(!(P2IN & BIT1));
      }
    }
    if (!(P1IN&BIT1))
    {
      __delay_cycles(50000);
      if (!(P1IN&BIT1))
      {
        P4OUT ^= BIT7;
        while(!(P1IN & BIT1));
      }
    }
  }
}
