#include <bits/stdc++.h>
#include "h26xparsec.h"
#include <fstream>
#include <cstdint>
#include <cstddef>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const std::string H264_URL = "video264.h264";
    const std::string H265_URL = "video265.h265";

    auto nalusH264 = H264_ExtractSPSPPSIDR(H264_URL);
    auto nalusH265 = H265_ExtractVPSSPSPPSIDR(H265_URL);

    H26X_DumpNalusToURL("image264.h264", nalusH264);
    H26X_DumpNalusToURL("image265.h265", nalusH265);

    return 0;
}
