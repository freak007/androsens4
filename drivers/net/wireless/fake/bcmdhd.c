#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/moduleparam.h>
#include <net/bcmdhd.h>

char current_path[MOD_PARAM_PATHLEN]; 

module_param_string(firmware_path, current_path, MOD_PARAM_PATHLEN, 0664);

static int __init m_init(void)
{
strcpy(current_path,"/system/etc/firmware/fw_bcm4329.bin");
pr_info("[FREAK007] Fake bcmdhd init\n");
return 0;
}


bool get_fake_firmware(int test)
{
printk(KERN_INFO "[FREAK007] fake driver status - firmware: %s", current_path);
if (strstr(current_path, "apsta")) {
 	return true;
} else {
	return false;
}
test = 1;
}

static void __exit m_exit(void)
{
pr_info("[FREAK007] Fake bcmdhd exit\n");
}

//EXPORT_SYMBOL(firmware_path);
EXPORT_SYMBOL(get_fake_firmware);
module_init(m_init);
module_exit(m_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("freak007");
