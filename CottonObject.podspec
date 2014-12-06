Pod::Spec.new do |s|
  s.name                  = "CottonObject"
  s.version               = "0.0.1"
  s.summary               = "A thin wrapper around NSDictionary to make life better with JSON (and other) network responses."
  s.description           = <<-DESC
                            CottonObject allows a developer to take the NSDictionary response and quickly wrap it in a formal Objective-C class. This has a number of benefits:
                            * Because the object uses NSDictionary as the data store, it can be easily de/serialized using the NSCoding protocol.
                            * Objects can be "faked" with dictionaries instanced from plists if your network or API is not up yet.
                            * Provides type-safe getters and setters to the dictionary. Missing or wrongly keyed values return nil and as long as your code supports that (it awlays should), you'll avoid crashes when your web endpoint results change unexpectedly.
                            * The property names are used as keys, eliminating the need for declaring string constants.
                            DESC
  s.homepage              = "https://github.com/hermiteer/CottonObject"
  s.license               = { :type => "MIT", :file => "LICENSE" }
  s.author                = "Christoph"
  s.ios.deployment_target = "5.0"
  s.osx.deployment_target = "10.6"
  s.source                = { :git => "https://github.com/hermiteer/CottonObject.git", :tag => "0.0.2" }
  s.source_files          = "Source/*"
  s.requires_arc          = true
end
