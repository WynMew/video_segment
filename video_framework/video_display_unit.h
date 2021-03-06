// Copyright (c) 2010-2014, The Video Segmentation Project
// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the The Video Segmentation Project nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---

#ifndef VIDEO_SEGMENT_VIDEO_FRAMEWORK_VIDEO_DISPLAY_UNIT_H__
#define VIDEO_SEGMENT_VIDEO_FRAMEWORK_VIDEO_DISPLAY_UNIT_H__

#include "base/base.h"
#include "video_framework/video_unit.h"

namespace cv {
  class Mat;
}

namespace video_framework {

struct VideoDisplayOptions {
  std::string stream_name = "VideoStream";
  float output_scale = 1.0f;
};

class VideoDisplayUnit : public VideoUnit {
public:
  VideoDisplayUnit(const VideoDisplayOptions& options);
  ~VideoDisplayUnit();

  VideoDisplayUnit(const VideoDisplayUnit&) = delete;
  VideoDisplayUnit& operator=(const VideoDisplayUnit&) = delete;

  virtual bool OpenStreams(StreamSet* set);
  virtual void ProcessFrame(FrameSetPtr input, std::list<FrameSetPtr>* output);
  virtual bool PostProcess(std::list<FrameSetPtr>* append);
private:
  VideoDisplayOptions options_;
  int video_stream_idx_;
  int display_unit_id_;

  std::string window_name_;
  std::unique_ptr<cv::Mat> frame_buffer_;

  static int display_unit_count;
};

}  // namespace video_framework.

#endif  // VIDEO_SEGMENT_VIDEO_FRAMEWORK_VIDEO_DISPLAY_UNIT_H__
