@file:Suppress("OPT_IN_USAGE")

import com.base.creatingIosNativePodspecExport
import com.base.syntheticPodfileGen
import com.base.syntheticXCodeprojsTarget
import com.base.updatePodspecFile
import com.codingfeline.buildkonfig.compiler.FieldSpec.Type.STRING
import com.google.devtools.ksp.gradle.KspTaskMetadata
import org.jetbrains.kotlin.gradle.dsl.JvmTarget
import org.jetbrains.kotlin.gradle.plugin.mpp.KotlinNativeTarget
import org.jetbrains.kotlin.gradle.targets.js.yarn.YarnLockMismatchReport
import org.jetbrains.kotlin.gradle.targets.js.yarn.YarnRootExtension
import org.jetbrains.kotlin.gradle.targets.native.tasks.PodBuildTask
import org.jetbrains.kotlin.gradle.targets.native.tasks.PodGenTask
import org.jetbrains.kotlin.gradle.tasks.KotlinCompilationTask
import org.jetbrains.kotlin.gradle.tasks.PodspecTask
import java.util.Properties

plugins {
    // kotlin多平台插件
    alias(libs.plugins.kotlin.multiplatform)
    // android应用插件
    alias(libs.plugins.android.application)
    // jetbrains compose插件
    alias(libs.plugins.jetbrains.compose)
    // kotlin cocoapods插件
    alias(libs.plugins.kotlin.cocoapods)
    alias(libs.plugins.compose.compiler)
}

configurations.all {
    resolutionStrategy {
        force("org.jetbrains.skiko:skiko:0.8.9")
    }
}
kotlin {
    applyDefaultHierarchyTemplate()
    androidTarget {
        compilerOptions {
            jvmTarget.value(JvmTarget.fromTarget(17))
        }
    }
    listOf(
//        iosX64(),
        iosArm64(),
        iosSimulatorArm64()
    ).forEach {
        it.binaries.framework {
            baseName = "ComposeApp"
            binaryOption("bundleId", configProperties.getProperty("BundleId"))
            if (System.getenv("XCODE_VERSION_MAJOR") == "1500") {
                linkerOpts += "-ld64"
            }
        }
    }


    cocoapods {
        summary = "ComposeApp"
        homepage = "."
        version = "1.0.0"
        license = "MIT"
        ios.deploymentTarget = 13
        source = "https://cdn.cocoapods.org"
        podfile = project.file("../iosApp/Podfile")
        this.framework {
            baseName = "ComposeApp"
            isStatic = true
        }

        pod("TencentMeetingSDK",path=project.file("src/nativeInterop/thirdparty/"))
        extraSpecAttributes["libraries"] = "'c++', 'sqlite3'" //导入系统库

        val tencentMeetingPath =
            projectDir.resolve("src/nativeInterop/thirdparty/TencentMeetingSDK")
        extraSpecAttributes["vendored_frameworks"] = """ 
           Dir.glob('${tencentMeetingPath.relativeTo(projectDir).path}/{*}.framework')${
            listOf<String>("").mapIndexed { _, s -> //Skia
            "f.include?('${s}.framework')"
        }.let {
            if(it.isNotEmpty()){//不为空,则排除,否则不加reject
                ".reject { |f| ${it.joinToString(" || ")}  }"
            }else it.joinToString("")
        }
        } + ['framework/${project.name}.framework']
        # framework/${project.name}.framework is ln file for buildDir
        """.trimIndent() //导入系统库
    }

    targets.withType<KotlinNativeTarget> {
        compilations.getByName("main") {
//            cinterops.create("TencentMeeting") {
//                definitionFile = tencentMeetingPath.resolve("TencentMeeting.def")
//                packageName = "meeting"
//                // 添加头文件目录
//                includeDirs(tencentMeetingPath.resolve("TencentMeetingSDK.framework/Headers"))
//                // 添加framework目录
//                // 动态加载所有 .framework
////                tencentMeetingPath.listFiles()?.filter {
////                    it.isDirectory &&
////                            it.name.endsWith(".framework")
////                }?.forEach {
////                    this.compilerOpts += "-l${it.name.removeSuffix(".framework")}"
////                }
//                this.compilerOpts += "-F${tencentMeetingPath.absolutePath}/"
//            }
        }
    }
}


compose.resources {
    publicResClass = true
    packageOfResClass = "${configProperties.getProperty("BundleId")}.resources"
    generateResClass = always
}