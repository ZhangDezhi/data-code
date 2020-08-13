digraph { // graph [fontname="Microsoft Yahei"];
 node [shape=plaintext, fontname="Microsoft Yahei"];
 机器地址; 存储数组的地址连续的内存块; 数组索引;
 node [shape=record];
 machineAddr [label="{10011101 | 10011110 | 10011111 | 10100000 | 10100001}", color=white];
 memoryBlock [label="{ | | | | }"];
 arrayIndices [label="{0 | 1 | 2 | 3 | 4}", color=white] 机器地址 -> machineAddr [style=invis]; 
存储数组的地址连续的内存块 -> memoryBlock; 
数组索引 -> arrayIndices [style=invis];
}
新細明體：PMingLiU細明體：MingLiU標楷體：DFKai-SB黑体：SimHei宋体：SimSun新宋体：NSimSun仿宋：FangSong楷体：KaiTi仿宋_GB2312：FangSong_GB2312楷体_GB2312：KaiTi_GB2312微軟正黑體：Microsoft JhengHei微软雅黑体：Microsoft YaHei


