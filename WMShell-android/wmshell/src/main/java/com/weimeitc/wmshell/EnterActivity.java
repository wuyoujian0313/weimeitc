package com.weimeitc.wmshell;


import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.os.Build;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.util.TypedValue;
import android.widget.Toast;

import com.ai.base.AIBaseActivity;
import com.ai.webplugin.AIWebViewActivity;
import com.ai.webplugin.config.GlobalCfg;

import java.io.InputStream;

public class EnterActivity extends AIBaseActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.splash_layout);
        initParam();
        requestPermission(Manifest.permission.CAMERA, 3000);
        requestPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE, 3000);
        enterHomeActivity();

    }

    // 检查某一项权限是否开启，并提示用户开启
    private void requestPermission(String permission, int requestCode) {
        int checkSelfPermission = ActivityCompat.checkSelfPermission(this, permission);
        if ( Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && checkSelfPermission == PackageManager.PERMISSION_DENIED) {
            if (ActivityCompat.shouldShowRequestPermissionRationale(this, permission)) {
                // 用户勾选了禁止后不在询问的选择

            } else {
                // 没有勾选，就提示申请权限
                ActivityCompat.requestPermissions(this, new String[]{permission}, requestCode);
            }
        }  else {
            //直接执行相应操作了
            // 执行自己后续的业务逻辑，比如拍照等等；
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        if (requestCode == 3000) {
            if (grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                // 已经开启权限
                // 执行自己后续的业务逻辑，比如拍照等等；
            } else {
                // Permission Denied
                // 用户选择了禁止使用
                Toast.makeText(EnterActivity.this, "您没有授权该权限，请在设置中打开授权", Toast.LENGTH_SHORT).show();
            }
            return;
        }
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }

    private void initParam() {
        GlobalCfg globalCfg = GlobalCfg.getInstance();
        try {
            InputStream is = getResources().getAssets().open("global.properties");
            globalCfg.parseConfig(is);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void enterHomeActivity() {
        Intent intent = new Intent(this, AIWebViewActivity.class);

        TypedValue typedValue = new TypedValue();
        getTheme().resolveAttribute(R.attr.colorPrimary, typedValue, true);
        final  int color = typedValue.data;
        intent.putExtra(AIWebViewActivity.backgroundColorKey, Color.WHITE);
        intent.putExtra(AIWebViewActivity.backgroundResIdKey,Color.WHITE);
        intent.putExtra(AIWebViewActivity.welcomeImageResId,R.mipmap.startpage);

        try {
            GlobalCfg globalCfg = GlobalCfg.getInstance();
            String flavor = BuildConfig.FLAVOR;
            if (flavor.equalsIgnoreCase("AIPlan")) {
                intent.putExtra(AIWebViewActivity.webViewURLKey,globalCfg.attr("online.addr"));
            } else {
                intent.putExtra(AIWebViewActivity.webViewURLKey,globalCfg.attr("online.addrTest"));
            }

            startActivity(intent);
            finish();
        } catch (Exception e) {
        }
    }
}
