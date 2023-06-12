#
# Be sure to run `pod lib lint UBiXMediationSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'UBiXMediationSDK'
  s.version          = '2.1.2.13'
  s.summary          = 'UBiX聚合广告变现SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/honourcoder/UBiXMediationSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'stefan.qi' => 'nianshiguang@126.com' }
  s.source           = { :git => 'https://github.com/honourcoder/UBiXMediationSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

#  s.source_files = 'UBiXMediationSDK/Classes/**/*'
  s.vendored_frameworks = ['UBiXMediationSDK/SDK/UbiXMediation.framework','UBiXMediationSDK/SDK/UbiXDaq.framework','UBiXMediationSDK/SDK/UbiXAdSDK.framework']
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
#  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  
  # s.resource_bundles = {
  #   'UBiXMediationSDK' => ['UBiXMediationSDK/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
#  s.dependency 'Ads-CN'
#  s.dependency 'GDTMobSDK'
#  s.dependency 'KSAdSDK', '~> 3.3.36'
#  s.dependency 'BaiduMobAdSDK'
  s.dependency 'JADYun'
end
