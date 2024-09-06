#include <bits/stdc++.h>
#include <fstream>
#include <cstdint>
#include <cstddef>
#include <fcntl.h>
#include <unistd.h>

#include "h26x_parser.h"

int main() {
    const std::string H264_URL = "video264.h264";
    const std::string H265_URL = "video265.h265";

    auto nalusH264 = h26x::H264ExtrackSPSPPSIDR(H264_URL);
    auto nalusH265 = h26x::H265ExtractVPSSPSPPSIDR(H265_URL);

    h26x::DumpNalu("image264.h264", nalusH264);
    h26x::DumpNalu("image265.h265", nalusH265);

    return 0;
}
