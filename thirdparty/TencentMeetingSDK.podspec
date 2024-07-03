# podspec can't be link relative for parent directory, so we change podspec file to parent directory 😂
Pod::Spec.new do |spec|
    spec.name                     = 'TencentMeetingSDK'
    spec.version                  = '1.0.0'
    spec.homepage                 = '.'
    spec.source                   = { :path=> '.'}
    spec.authors                  = ''
    spec.license                  = 'MIT'
    spec.summary                  = 'TencentMeetingSDK'
    spec.source_files = 'TencentMeetingSDK/**/*.{h,m}' #,swift
    spec.public_header_files = 'TencentMeetingSDK/**/*.h'
    spec.ios.deployment_target    = '13.0'
    spec.vendored_frameworks = Dir.glob('TencentMeetingSDK/{*}.framework') #.reject { |f| f.include?('Skia.framework') }
    spec.swift_version = '5.0'
end