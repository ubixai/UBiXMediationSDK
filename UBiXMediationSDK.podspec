#
# Be sure to run `pod lib lint UBiXMediationSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'UBiXMediationSDK'
  s.version          = '2.4.1.03'
  s.summary          = 'UBiX聚合广告变现SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://www.ubixai.com/product/md'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'stefan.qi' => 'stefan.qi@ubixai.com' }
  s.source           = { :git => 'https://github.com/honourcoder/UBiXMediationSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '10.0'

#  s.source_files = 'UBiXMediationSDK/Classes/**/*'
  s.vendored_frameworks = ['UBiXMediationSDK/SDK/UbiXMediation.framework']
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
#  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  
  # s.resource_bundles = {
  #   'UBiXMediationSDK' => ['UBiXMediationSDK/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'UIKit', 'MapKit', 'WebKit', 'MediaPlayer', 'CoreLocation', 'AdSupport', 'CoreMedia', 'AVFoundation', 'CoreTelephony', 'StoreKit', 'SystemConfiguration', 'MobileCoreServices', 'CoreMotion', 'Accelerate','AudioToolbox','JavaScriptCore','Security','CoreImage','AudioToolbox','ImageIO','QuartzCore','CoreGraphics','CoreText'
  s.weak_frameworks = 'AppTrackingTransparency', 'DeviceCheck'
  s.libraries = 'c++', 'resolv', 'z', 'sqlite3', 'bz2', 'xml2', 'iconv', 'c++abi'
#  s.dependency 'Ads-Fusion-CN-Beta/BUAdSDK','5.6.0.5'
#  s.dependency 'Ads-Fusion-CN-Beta/CSJMediation','5.6.0.5'
#  s.dependency pod 'Ads-CN', '5.6.0.7'
#  s.dependency 'GDTMobSDK', '4.14.45'
#  s.dependency 'KSAdSDK', '3.3.53'
#  s.dependency 'BaiduMobAdSDK', '5.322'
#  s.dependency 'JADYun', '2.4.6'

  s.default_subspec = 'UbiXAdSDK', 'UbiXDaq'

  s.subspec 'UbiXDaq' do |sp|
    sp.name             = 'UbiXDaq'
    sp.vendored_frameworks = ['UBiXMediationSDK/SDK/UbiXDaq.framework']
  end

  s.subspec 'UbiXAdSDK' do |sp|
    sp.name             = 'UbiXAdSDK'
    sp.vendored_frameworks = ['UBiXMediationSDK/SDK/UbiXAdSDK.framework']
    sp.dependency 'UBiXMediationSDK/UbiXDaq'
  end 

  

end
