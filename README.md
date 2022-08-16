# RG-E EPICS Support
EPICS support directory for the RG-E double target system.
The `$EPICS_BASE/support/galil/3-6` directory contains the target system's IOC.
The PVs specific to the target can be found on the `$EPICS_BASE/support/galil/3-6/db/galil_userdef_records.template` directory.

## Versions
* EPICS base: 3.14.8.2.
* SNCSEQ:     2.1.21.
* IPAC:       2.15.
* SSCAN:      2.11.2.
* AUTOSAVE:   5.7.1.
* ASYN:       4.37.
* CALC:       3.7.3.
* MOTOR       7.1.
* BUSY:       1.7.1.
* GALIL:      3.6.

## PVs
* ai `DMC01:A_curr_pos`.
    Current position of the band.
    Displayed at the GUI and used for internal calculations.
* ai `DMC01:A_home`.
    Position of the home.
    Displayed at the GUI and used for calculations.
* ai `DMC01:A_pos#`, where # is a number from 1 to 7.
    Positions of each of the seven targets.
    Displayed at the GUI and used for calculations.
* ai `DMC01:A_lowlimit`.
    Position of the low limit.
    If `DMC01:A_curr_pos` is lesser than this value, a major alarm is fired.
* ai `DMC01:A_highlimit`.
    Position of the high limit.
    If `DMC01:A_curr_pos` is greater than this value, a major alarm is fired.
* ai `DMC01:A_tolerance`.
    Equivalence tolerance for the position of each target and the position of the band.
* ao `DMC01:A_go_home`.
    Command to move the band to the home position, as defined in `DMC01:A_home`.
* ao `DMC01:A_go_pos#`.
    Command to move the band to the position of target #, as defined in `DMC01:A_pos#`.
* calc `DMC01:A_at_home`.
    Calculation that checks if the band position is equal to the home position in `DMC01:A_home`, within the tolerance margin defined by `DMC01:A_tolerance`.
* calc `DMC01:A_at_pos#`.
    Calculation that checks if the band position is equal to that of target # in `DMC01:A_pos#`, within the tolerance margin `DMC01:A_tolerance`.
* calc `DMC01:A_at_lowlimit`.
    Calculation that checks if the band position is lesser than the low limit `DMC01:A_lowlimit`.
* calc `DMC01:A_at_highlimit`.
    Calculation that checks if the band position is greater than the high limit `DMC01:A_lowlimit`.
* calc `DMC01:A_calc_pos#`.
    Calculation that checks if the condition in `DMC01:A_at_pos#` is met.
    If true, it returns #.
    If # = 1 and the check is false, returns 0.
    Otherwise, it returns the calculation of #-1.
    This PV is needed to avoid an internal limit of calculation PVs in EPICS, which is that their argument is limited to 40 characters.
* calc `DMC01:A_calc_home`.
    Calculation that checks if the condition in `DMC01:A_at_home` is met.
    Returns 10 if true and `DMC01:A_calc_pos7` if false.
* calc `DMC01:A_calc_lowlimit`.
    Calculation that checks if the condition in `DMC01:A_at_lowlimit` is met.
    Returns 11 if true and `DMC01:A_calc_home` if false.
* calc `DMC01:A_calc_highlimit`.
    Calculation that checks if the condition in `DMC01:A_at_highlimit` is met.
    Returns 12 if true and `DMC01:A_calc_lowlimit` if false.
* calc `DMC01:A_calc_tgttype.
    Calculation that calls `DMC01:A_calc_highlimit`, thus calling the others in sequence.
    Depending on where the band is, it can return the target number, 10 if its at the home, 11 if its lesser than the low limit, 12 if its greater than the high limit, and 0 if its not at a predefined position.
* mbbi `DMC01:A_tgttype`.
    mbbi that encodes the output of `DMC01:A_calc_tgttype` with a string and an alarm level.

    | **Value** | **Name**   | **Alarm Severity** |
    | --------- | ---------- | ------------------ |
    |  0        | Unknown    | Minor              |
    |  1        | Target 1   | No alarm           |
    |  2        | Target 2   | No alarm           |
    |  3        | Target 3   | No alarm           |
    |  4        | Target 4   | No alarm           |
    |  5        | Target 5   | No alarm           |
    |  6        | Target 6   | No alarm           |
    |  7        | Target 7   | No alarm           |
    | 10        | Home       | No alarm           |
    | 11        | Low Limit  | Major              |
    | 12        | High Limit | Major              |

* ai `DMC01:COMMERR_STATUS`.
    Variable that is true when there's a communication error with the controller and false otherwise.
    Used for triggering a communication alarm.
* ai `IOC01:SR_i_am_alive`.
    Variable that is true when the IOC is up and running, false otherwise.
    Used for triggering a communication alarm.

## Alarms
| **Name**               | **Trigger**                 | **Severity** |
| ---------------------- | --------------------------- | ------------ |
| Unknown band position  | `DMC01:A_tgttype      =  0` | Minor        |
| Band beyond low limit  | `DMC01:A_tgttype      = 11` | Major        |
| Band beyond high limit | `DMC01:A_tgttype      = 12` | Major        |
| Controller comm. error | `DMC01:COMMERR_STATUS =  1` | Major        |
| IOC comm. error        | `IOC01:SR_i_am_alive  =  0` | Major        |

*For further details, check the double target engineering notes.*
