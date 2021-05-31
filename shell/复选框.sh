#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-05-28 13:28
# Last Modified  : 2021-05-28 13:31:51
# This is a Script.
#------------------------------------------

whiptail --checklist "Please pick one" 10 60 5 one one off two two off\
three three off four four off  five five off


#
#  ┌──────────────────────────────────────────────────────────┐
#  │    [ ] one    one                                        │ 
#  │    [*] two    two                                        │ 
#  │    [ ] three  three                                      │ 
#  │    [*] four   four                                       │ 
#  │    [ ] five   five                                       │ 
#  │                                                          │ 
#  │              <Ok>                  <Cancel>              │ 
#  │                                                          │ 
#  └──────────────────────────────────────────────────────────┘ 
#  "two" "four"$
#

