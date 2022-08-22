/*
 * @Author: Zhiyuan Cao
 * @Date: 2022-08-22 19:09:38
 * @LastEditors: Zhiyuan Cao
 * @LastEditTime: 2022-08-22 19:41:12
 * @FilePath: /xv6-labs-2021/user/pingpong.c
 * @Description:
 *
 * Copyright (c) 2022 by Zhiyuan Cao, All Rights Reserved.
 */
#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int p[2];
    int cpid;
    int pid;
    int status;
    pipe(p);
    char c = 'a';
    pid = fork();
    if (pid == 0)
    {
        read(p[0], &cpid, sizeof(int));
        fprintf(1, "%d: received ping\n", cpid);
        write(p[1], &c, 1);
        close(p[1]);
        exit(0);
    }
    else
    {
        write(p[1], &pid, 1);
        wait(&status);
        read(p[0], &c, 1);
        close(p[0]);
        pid = getpid();
        fprintf(1, "%d: received pong\n", pid);
        exit(0);
    }
}