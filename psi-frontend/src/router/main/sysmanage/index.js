const routes = [
  {
    path: '/un-1',
    name: 'UN1',
    component: () => import('@/views/status/404.vue')
  },
  {
    path: '/un-2',
    name: 'UN2',
    component: () => import('@/views/status/403.vue')
  },
  {
    path: '/un-3',
    name: 'UN3',
    component: () => import('@/views/status/404.vue')
  },
  {
    path: '/un-4',
    name: 'UN4',
    component: () => import('@/views/status/403.vue')
  },
  {
    path: '/un-5',
    name: 'UN5',
    component: () => import('@/views/status/404.vue')
  },
  {
    path: '/un-6',
    name: 'UN6',
    component: () => import('@/views/status/403.vue')
  },
  {
    path: '/component/form',
    name: 'search',
    component: () => import('@/components/form/demo.vue')
    // component: () => import('../../../components/psiSearch/demo.vue')
  },
  {
    path: '/component/table',
    name: 'table',
    component: () => import('@/components/table/demo.vue')
  },
  {
    path: '/component/dialog',
    name: 'dialog',
    component: () => import('@/components/dialog/demo.vue')
  },
  {
    path: '/component/drawer',
    name: 'drawer',
    component: () => import('@/components/drawer/demo.vue')
  },
  {
    path: '/component/custom',
    name: 'custom',
    component: () => import('@/components/custom/index.vue')
  },
  {
    path: '/component/center',
    name: 'center',
    component: () => import('@/components/center/index.vue')
  },
  {
    path: '/pay/payable/check',
    name: 'check',
    component: () =>
      import('@/views/yingfuyufukuan/payables/FinPayableCheck.vue')
  },
  {
    path: '/1/2/3',
    name: '3',
    component: () =>
      import('@/views/yingfuyufukuan/yingfuguanli/CaiGouYingFu.vue')
  },
  {
    path: '/sysmanagement/rolemanagement',
    name: 'rolemanagement',
    component: () => import('@/views/sysmanage/RoleManage.vue')
  },
  {
    path: '/sysmanagement/menumanagement',
    name: 'menumanagement',
    component: () => import('@/views/sysmanage/MenuManage.vue')
  },
  {
    path: '/sysmanagement/usermanagement',
    name: 'usermanagement',
    component: () => import('@/views/sysmanage/UserManage.vue')
  }
]

export default routes
