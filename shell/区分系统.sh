#参考: https://wxnacy.com/2017/11/24/get-os-name/
#区分Linux/Mac
$uname

#区分Linux发行版
$ source /etc/os-release
$ echo $ID      # --> ubuntu



OS=$(uname -s)
if [ ${OS} == "Darwin"  ];then
    sudo brew install git
elif [ ${OS} == "Linux"  ];then
    source /etc/os-release
    case $ID in
        debian|ubuntu|devuan)
            sudo apt-get install git
            ;;
        centos|fedora|rhel)
            yumdnf="yum"
            if test "$(echo "$VERSION_ID >= 22" | bc)" -ne 0;
            then
                yumdnf="dnf"
            fi
            sudo $yumdnf install -y git
            ;;
        *)
            exit 1
            ;;
    esac
else
    echo "Other OS: ${OS}"
fi



#CentOS
# NAME="CentOS Linux"
# VERSION="7 (Core)"
# ID="centos"
# ID_LIKE="rhel fedora"
# VERSION_ID="7"
# PRETTY_NAME="CentOS Linux 7 (Core)"
# ANSI_COLOR="0;31"
# CPE_NAME="cpe:/o:centos:centos:7"
# HOME_URL="https://www.centos.org/"
# BUG_REPORT_URL="https://bugs.centos.org/"
# 
# CENTOS_MANTISBT_PROJECT="CentOS-7"
# CENTOS_MANTISBT_PROJECT_VERSION="7"
# REDHAT_SUPPORT_PRODUCT="centos"
# REDHAT_SUPPORT_PRODUCT_VERSION="7"


#Ubuntu
# NAME="Ubuntu"
# VERSION="16.04.2 LTS (Xenial Xerus)"
# ID=ubuntu
# ID_LIKE=debian
# PRETTY_NAME="Ubuntu 16.04.2 LTS"
# VERSION_ID="16.04"
# HOME_URL="http://www.ubuntu.com/"
# SUPPORT_URL="http://help.ubuntu.com/"
# BUG_REPORT_URL="http://bugs.launchpad.net/ubuntu/"
# VERSION_CODENAME=xenial
# UBUNTU_CODENAME=xenial