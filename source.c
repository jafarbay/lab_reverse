
undefined8 main(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long in_FS_OFFSET;
  uint local_34 [9];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_34[6] = 1;
  local_34[0] = 3;
  local_34[1] = 0;
  local_34[2] = 0;
  local_34[3] = 0;
  local_34[7] = 0;
  local_34[8] = 0;
  local_34[4] = 0;
  __get_cpuid(1,local_34,local_34 + 1,local_34 + 2,local_34 + 3);
  local_34[7] = local_34[0] << 0x18 |
                local_34[0] >> 0x18 | (local_34[0] & 0xff00) << 8 | local_34[0] >> 8 & 0xff00;
  local_34[8] = local_34[3] << 0x18 |
                local_34[3] >> 0x18 | (local_34[3] & 0xff00) << 8 | local_34[3] >> 8 & 0xff00;
  snprintf(PSN,0x11,"%08X%08X",local_34[7],local_34[8]);
  calc_md5(PSN,0x10);
  for (local_34[5] = 0; (int)local_34[5] < 0x10; local_34[5] = local_34[5] + 1) {
    sprintf(md5decode + (int)(local_34[5] * 2),"%02x",
            (uint)(byte)md5digest[(int)(0xf - local_34[5])]);
  }
  readlink("/proc/self/exe",binaryPath,0x1000);
  getxattr(binaryPath,"user.license",xattrValue,0x1000);
  puts("Welcome to Lab2 super secure program!");
  iVar1 = strncmp(md5decode,xattrValue,0x21);
  if (iVar1 == 0) {
    local_34[4] = 1;
  }
  if (local_34[4] == 0) {
    printf("Your HWID is %08X%08X.\nEnter the license key: ",local_34[7],local_34[8]);
    __isoc99_scanf(&DAT_0010208f,userInput);
    iVar1 = strncmp(md5decode,userInput,0x21);
    if (iVar1 == 0) {
      setxattr(binaryPath,"user.license",md5decode,0x21,0);
      puts("Now you app is activated! Thanks for purchasing!");
    }
    else {
      puts("Provided key is wrong! App is closing!");
    }
  }
  else if (local_34[4] == 1) {
    puts("Your app is licensed to this PC!");
  }
  system("read -p \'Press Enter to continue...\' var");
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}


