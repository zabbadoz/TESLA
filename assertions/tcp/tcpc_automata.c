/*
 * This file is autogenerated by the Tesla CFA compiler
 * via: ../../cfa/splc -t tesla -s tcpc tcpc.spl
 */

#include <sys/types.h>

#ifdef _KERNEL
#else
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <strings.h>
#endif

#include <tesla/tesla_state.h>
#include <tesla/tesla_util.h>

#include <tcpc_defs.h>

struct tcp_connect {
  u_int state : 5;
  u_int active_close_return : 1;
  u_int established_return : 1;
} __attribute__((__packed__));

#define TCP_CONNECT_PTR(tip) ((unsigned char *)((tip)->ti_state))
#define TCP_CONNECT_STATE(tip,off) ((struct tcp_connect *)(TCP_CONNECT_PTR(tip)+(off)+1))
#define TCP_CONNECT_NUM_STATES(tip) (TCP_CONNECT_PTR(tip)[0])

void
tcpc_automata_init(struct tesla_instance *tip) {
  TCP_CONNECT_NUM_STATES(tip) = 1;
  TCP_CONNECT_STATE(tip,0)->state = 6; /* S_initial_24 */
  TCP_CONNECT_STATE(tip,0)->active_close_return = 0;
  TCP_CONNECT_STATE(tip,0)->established_return = 0;
}

int
tcpc_automata_prod(struct tesla_instance *tip, u_int event)
{
  unsigned char newstate[16];
  u_int i, curpos=1;
  struct tcp_connect tmpstate;
  bzero(newstate, sizeof(newstate));
  switch (event) {
  case 0:  /* EVENT_CLOSING */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 10:
        /* event S_or_5 -> S_seq_6 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 12;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  case 1:  /* EVENT_SYN_RECEIVED */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 4:
        /* event S_or_29 -> S_or_32 */
        /* register established_return = 1 */
        /* event S_or_29 -> S_initial_12 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = 1;
        tmpstate.state = 20;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        /* event S_or_29 -> S_or_36 */
        /* register active_close_return = 1 */
        /* event S_or_29 -> S_initial_1 */
        tmpstate.active_close_return = 1;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 9;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  case 2:  /* EVENT_FIN_WAIT_1 */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 9:
        /* event S_initial_1 -> S_or_5 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 10;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        /* event S_initial_1 -> S_or_8 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 14;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  case 3:  /* EVENT_FIN_WAIT_2 */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 14:
        /* event S_or_8 -> S_seq_9 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 8;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  case 4:  /* EVENT_SYN_SENT */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 7:
        /* event S_seq_26 -> S_or_29 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 4;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        /* event S_seq_26 -> S_or_40 */
        /* register established_return = 0 */
        /* event S_seq_26 -> S_initial_12 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = 0;
        tmpstate.state = 20;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  case 5:  /* EVENT_CLOSED */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 6:
        /* event S_initial_24 -> S_seq_26 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 7;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      case 11:
        /* event S_either_or_4 -> S_final_2 */
        switch (TCP_CONNECT_STATE(tip,i)->active_close_return) {
         case 1:
          /* event S_either_or_4 -> S_final_25 */
          tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
          tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
          tmpstate.state = 2;
          memcpy(&(newstate[curpos]), &tmpstate, 1);
          curpos++;
          break;
         case 0:
          /* event S_either_or_4 -> S_final_13 */
          switch (TCP_CONNECT_STATE(tip,i)->established_return) {
           case 0:
            /* event S_either_or_4 -> S_final_25 */
            tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
            tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
            tmpstate.state = 2;
            memcpy(&(newstate[curpos]), &tmpstate, 1);
            curpos++;
            break;
           case 1:
            /* event S_either_or_4 -> S_final_25 */
            tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
            tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
            tmpstate.state = 2;
            memcpy(&(newstate[curpos]), &tmpstate, 1);
            curpos++;
            break;
           default:
            return 1; /* TESLA_INTERNAL_ERROR */
          }
          break;
         default:
          return 1; /* TESLA_INTERNAL_ERROR */
        }
        break;
      case 18:
        /* event S_seq_22 -> S_final_13 */
        switch (TCP_CONNECT_STATE(tip,i)->established_return) {
         case 0:
          /* event S_seq_22 -> S_final_25 */
          tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
          tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
          tmpstate.state = 2;
          memcpy(&(newstate[curpos]), &tmpstate, 1);
          curpos++;
          break;
         case 1:
          /* event S_seq_22 -> S_final_25 */
          tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
          tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
          tmpstate.state = 2;
          memcpy(&(newstate[curpos]), &tmpstate, 1);
          curpos++;
          break;
         default:
          return 1; /* TESLA_INTERNAL_ERROR */
        }
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  case 6:  /* EVENT_CLOSE_WAIT */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 16:
        /* event S_or_20 -> S_seq_21 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 15;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  case 7:  /* EVENT_ESTABLISHED */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 20:
        /* event S_initial_12 -> S_or_16 */
        /* register active_close_return = 0 */
        /* event S_initial_12 -> S_initial_1 */
        tmpstate.active_close_return = 0;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 9;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        /* event S_initial_12 -> S_or_20 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 16;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  case 8:  /* EVENT_LAST_ACK */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 15:
        /* event S_seq_21 -> S_seq_22 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 18;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  case 9:  /* EVENT_TIME_WAIT */
    for (i=0; i < TCP_CONNECT_NUM_STATES(tip); i++) {
      switch (TCP_CONNECT_STATE(tip,i)->state) {
      case 8:
        /* event S_seq_9 -> S_either_or_4 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 11;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      case 12:
        /* event S_seq_6 -> S_either_or_4 */
        tmpstate.active_close_return = TCP_CONNECT_STATE(tip,i)->active_close_return;
        tmpstate.established_return = TCP_CONNECT_STATE(tip,i)->established_return;
        tmpstate.state = 11;
        memcpy(&(newstate[curpos]), &tmpstate, 1);
        curpos++;
        break;
      default:
        break;
      }
    }
    newstate[0] = curpos-1;
    if (newstate[0] == 0)
      return 1; /* TESLA_ERROR */
    memcpy(TCP_CONNECT_PTR(tip), &newstate, sizeof(newstate));
    return 0;

  default:
    return 1; /* TESLA_UNKNOWN_EVENT */
  }
}

