# AMDProfileControl
code to take AMDProfileControl's APIs for a spin

Profiling a simple matrix multiplication opeartion 10,000 times

## Commands

### Creating binary

```bash
g++ -std=c++11 matrix_mult.cpp profile_matrix_mult.cpp -o matrix_mult -I /opt/AMDuProf_4.0-341/include -L /opt/AMDuProf_4.0-341/lib/x64  -lAMDProfileController -lrt -pthread
```

### Collecting data

```bash
AMDuProfCLI collect --config tbp --start-paused -o /tmp/cpuprof-tbp ./matrix_mult 
```

### Create report from data

```bash
AMDuProfCLI report -i <generated output path from data collection>
```


## System information

Experiments performed on Kepler2

```zsh
╰─± AMDuProfCLI info --system              
[OS Info]
        OS Details              : LinuxUbuntu 20.04.5 LTS-64
        Distribution Details    : debian 20.04
        Kernel Details          : 5.4.0

[CPU Info]
        AMD Cpu                 : Yes
        Family                  : 0x19
        Model                   : 0x01
        Stepping                : 0x1
        Local APIC              : Yes
        Socket Count            : 2    
        SMT Enabled             : Yes
        Threads per Core        : 2   
        Threads per CCX         : 16  
        Threads per Package     : 64  
        Total number of Threads : 128

[PERF Features Availability]
        Core PMC                : Yes
        L3 PMC                  : Yes
        DF PMC                  : Yes
        PERF TS                 : No

[IBS Features Availability]
        IBS                     : Yes
        IBS Fetch Sampling      : Yes
        IBS OP Sampling         : Yes
        IBS FetchCtlExtd        : Yes
        IBS ExtCount            : Yes
        IBS Dispatch            : Yes
        IBS BrTgtAddr           : Yes
        IBS OpData4             : No

[RAPL/CEF Features Availability]
        RAPL                    : Yes
        APERF & MPERF           : Yes
        Read Only APERF & MPERF : Yes
        IRPERF                  : Yes
        HW P-State Control      : Yes

[PERF features supported by OS]
        TBP Supported           : Yes
        EBP Supported           : Yes
        IBS Supported           : Yes
        IRPERF Supported        : Yes
        APERF Supported         : Yes
        MPERF Supported         : Yes
        BPF Supported        : No
        BCC Installed        : No
        Perf Event Paranoid     : 2
        Perf Event Max Mlock    : 516 KB
        Perf Event Max Stack    : 127

[Hypervisor Info]
        Hypervisor Enabled      : No
```